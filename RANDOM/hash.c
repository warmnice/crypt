//利用hash函数寻找本地硬盘重复文件
#include"random.h"
void hash(){
	FileHash hashTable[MAX_FILES];
    int hashTableSize = 0;
    // 指定要扫描的目录
    const char *directoryPath = "E:\\";
    // 遍历目录并记录文件哈希值
    traverseDirectory(directoryPath, hashTable, &hashTableSize);
    // 查找重复文件并生成报告
    findDuplicateFiles(hashTable, hashTableSize);
}

