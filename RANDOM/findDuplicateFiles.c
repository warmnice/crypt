// 查找重复文件并生成报告
#include"random.h"
void findDuplicateFiles(const FileHash hashTable[], int hashTableSize) {
    // 遍历哈希表，查找具有相同哈希值的文件
    // 如果文件内容相同，输出到报告中
    // 否则，标记为哈希冲突
    for (int i = 0; i < hashTableSize; i++) {
        for (int j = i + 1; j < hashTableSize; j++) {
            if (memcmp(hashTable[i].hash, hashTable[j].hash, SHA256_DIGEST_LENGTH) == 0) {
                printf("重复文件:\n%s\n%s\n", hashTable[i].filename, hashTable[j].filename);
            }
        }
    }
}

