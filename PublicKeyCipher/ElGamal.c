#include"key.h"
// ELGamal算法
void ELGamal(int p, int *g_temp, int num){
	//随机选择原根g
	srand(time(NULL));
	int g = g_temp[rand() % num]; 
	//随机生成私钥x
    int x = 2 + rand() % (p - 3);  //私钥x
    //随机选取整数k 
    int k = 2 + rand() % (p - 3);
    //计算公钥y
    int y = ModExp(g, x, p);
    printf("\n请输入明文：");
    int plaintext;
    scanf("%d",&plaintext);getchar();
    //加密
    int encryptedResult = (plaintext * ModExp(y, k, p)) % p;
    printf("加密结果为：%d", encryptedResult);
    int a = ModExp(g, k, p);
    printf("\n请输入密文：");
    int ciphertext;
    scanf("%d",&ciphertext);getchar();
    //解密
    int decryptedResult = (ciphertext * ModExp(a, p - 1 - x, p)) % p;
    printf("解密结果为: %d\n", decryptedResult);
}
