// ����Ŀ¼����¼�ļ���ϣֵ
#include"random.h"
void traverseDirectory(const char *dirPath, FileHash hashTable[], int *hashTableSize) {
    // ʵ��Ŀ¼�����Ĵ��룬�ݹ��ѭ������Ŀ¼�е��ļ�����Ŀ¼����ÿ���ļ������ϣֵ��������ϣֵ���ļ�·����¼����ϣ����
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    if(dir == NULL){
        perror("�ļ���ʧ�ܣ�");
        exit(1);
    }
    while((entry = readdir(dir)) != NULL){
    	char filePath[256];
    	snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
    	struct stat fileStat;
    	if(stat(filePath, &fileStat) < 0){
        	perror("��ȡ�ļ�״̬����");
        	exit(1);
    	}
    	if(S_ISDIR(fileStat.st_mode)){
            // ���� "." �� ".." Ŀ¼
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            // �ݹ������Ŀ¼
            traverseDirectory(filePath, hashTable, hashTableSize);
        }else if(S_ISREG(fileStat.st_mode)){
            if(calculateHash(filePath, hashTable[*hashTableSize].hash)){
                strncpy(hashTable[*hashTableSize].filename, filePath, sizeof(hashTable[*hashTableSize].filename));
                (*hashTableSize)++;
            }else{
                fprintf(stderr, "�����ļ���ϣֵ����: %s\n", filePath);
            }
        }
	}
    closedir(dir);
}

