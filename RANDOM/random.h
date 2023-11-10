#include"stdio.h"
#include"math.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dirent.h>
#include <sys/stat.h>

#define FORMAT 5 //�������Ӷ���ʽ��ϵ������
#define RANDOM_LENGTH 16 // ���г���
#define JUDGE_NUM 0.5 // ����Ƿ�ͨ�����жϱ�׼
#define D 4 //����ؼ���еõ��������趨������λ��
#define RC4_S_LENGTH 256//RC4�㷨��S�еĳ��� 
#define KEY_S_LENGTH 16//RC4�㷨��������Կ�ĳ���
#define MAX_KEY_LEANTH 8//RC4�㷨�����Կ�λ�� 
#define MAX_HASH_LEN (SHA256_DIGEST_LENGTH * 2) // SHA-256�����Ĺ�ϣֵ��ϣֵ��ʮ�������ַ�������
#define MAX_FILES 1000

// �ṹ��ʾ�ļ��Ĺ�ϣ��
typedef struct {
    char hash[MAX_HASH_LEN + 1];// +1���ڴ洢��ֹ��null
    char filename[256];
} FileHash;

//���LSR����������е������
void LSR_test();
//16λLSR�����������
int linear_shift_register();
//������Ƶ����� 
void single_bit_frequency_test();
//�α�ֲ���� 
void cursor_distribution_test();
//����ؼ�� 
void autocorrelation_test();

//RC4������I��J�ı仯����
void RC4();
//���������� 
void swap(int* a, int* b);

//����hash����Ѱ�ұ���Ӳ���ظ��ļ�
void hash();
//�����ļ���SHA-256��ϣֵ
int calculateHash(const char *filename, unsigned char hash[SHA256_DIGEST_LENGTH]);
// ����Ŀ¼����¼�ļ���ϣֵ
void traverseDirectory(const char *dirPath, FileHash hashTable[], int *hashTableSize);
// �����ظ��ļ������ɱ���
void findDuplicateFiles(const FileHash hashTable[], int hashTableSize);
