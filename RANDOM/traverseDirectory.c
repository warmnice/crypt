// 遍历目录并记录文件哈希值
#include"random.h"
void traverseDirectory(const char *dirPath, FileHash hashTable[], int *hashTableSize) {
    // 实现目录遍历的代码，递归或循环遍历目录中的文件和子目录，对每个文件计算哈希值，并将哈希值与文件路径记录到哈希表中
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    if(dir == NULL){
        perror("文件打开失败！");
        exit(1);
    }
    while((entry = readdir(dir)) != NULL){
    	char filePath[256];
    	snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
    	struct stat fileStat;
    	if(stat(filePath, &fileStat) < 0){
        	perror("获取文件状态出错！");
        	exit(1);
    	}
    	if(S_ISDIR(fileStat.st_mode)){
            // 忽略 "." 和 ".." 目录
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            // 递归遍历子目录
            traverseDirectory(filePath, hashTable, hashTableSize);
        }else if(S_ISREG(fileStat.st_mode)){
            if(calculateHash(filePath, hashTable[*hashTableSize].hash)){
                strncpy(hashTable[*hashTableSize].filename, filePath, sizeof(hashTable[*hashTableSize].filename));
                (*hashTableSize)++;
            }else{
                fprintf(stderr, "计算文件哈希值出错: %s\n", filePath);
            }
        }
	}
    closedir(dir);
}

