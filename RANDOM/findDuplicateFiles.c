// �����ظ��ļ������ɱ���
#include"random.h"
void findDuplicateFiles(const FileHash hashTable[], int hashTableSize) {
    // ������ϣ�����Ҿ�����ͬ��ϣֵ���ļ�
    // ����ļ�������ͬ�������������
    // ���򣬱��Ϊ��ϣ��ͻ
    for (int i = 0; i < hashTableSize; i++) {
        for (int j = i + 1; j < hashTableSize; j++) {
            if (memcmp(hashTable[i].hash, hashTable[j].hash, SHA256_DIGEST_LENGTH) == 0) {
                printf("�ظ��ļ�:\n%s\n%s\n", hashTable[i].filename, hashTable[j].filename);
            }
        }
    }
}

