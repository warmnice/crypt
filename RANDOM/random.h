#include"stdio.h"
#include"math.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dirent.h>
#include <sys/stat.h>

#define FORMAT 5 //保存连接多项式的系数个数
#define RANDOM_LENGTH 16 // 序列长度
#define JUDGE_NUM 0.5 // 检测是否通过的判断标准
#define D 4 //自相关检测中得到新序列设定的左移位数
#define RC4_S_LENGTH 256//RC4算法里S盒的长度 
#define KEY_S_LENGTH 16//RC4算法里种子密钥的长度
#define MAX_KEY_LEANTH 8//RC4算法里的密钥最长位数 
#define MAX_HASH_LEN (SHA256_DIGEST_LENGTH * 2) // SHA-256产生的哈希值哈希值的十六进制字符串长度
#define MAX_FILES 1000

// 结构表示文件的哈希项
typedef struct {
    char hash[MAX_HASH_LEN + 1];// +1用于存储终止的null
    char filename[256];
} FileHash;

//检测LSR生成随机序列的随机性
void LSR_test();
//16位LSR生成随机序列
int linear_shift_register();
//单比特频数检测 
void single_bit_frequency_test();
//游标分布检测 
void cursor_distribution_test();
//自相关检测 
void autocorrelation_test();

//RC4密码里I、J的变化规律
void RC4();
//交换两个数 
void swap(int* a, int* b);

//利用hash函数寻找本地硬盘重复文件
void hash();
//计算文件的SHA-256哈希值
int calculateHash(const char *filename, unsigned char hash[SHA256_DIGEST_LENGTH]);
// 遍历目录并记录文件哈希值
void traverseDirectory(const char *dirPath, FileHash hashTable[], int *hashTableSize);
// 查找重复文件并生成报告
void findDuplicateFiles(const FileHash hashTable[], int hashTableSize);
