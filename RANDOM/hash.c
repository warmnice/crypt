//����hash����Ѱ�ұ���Ӳ���ظ��ļ�
#include"random.h"
void hash(){
	FileHash hashTable[MAX_FILES];
    int hashTableSize = 0;
    // ָ��Ҫɨ���Ŀ¼
    const char *directoryPath = "E:\\";
    // ����Ŀ¼����¼�ļ���ϣֵ
    traverseDirectory(directoryPath, hashTable, &hashTableSize);
    // �����ظ��ļ������ɱ���
    findDuplicateFiles(hashTable, hashTableSize);
}

