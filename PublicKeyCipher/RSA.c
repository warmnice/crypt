#include"key.h"
//RSA算法
void RSA(int p, int q){
    //计算n和欧拉函数m 
    int n = p * q;
    int m = (p - 1) * (q - 1);
    //选择公钥e
    int prime[m - 1 - 1];//保存可能的公钥结果 
    int num = 0;//可能的公钥数量 
    for (int i = 2; i < m ; i++) {
    	if(isPrime(i)) prime[num++] =  i; 
	}
	srand(time(NULL));
	int e = prime[rand() % num];
    //计算私钥d
    int d = 0;
    for (int i = 1; i < m; i++) {
        if ((i * e) % m == 1) {
            d = i;
            break;
        }
    }
    printf("请输入明文：");
    int plaintext;
    scanf("%d",&plaintext);getchar();
    //加密
    int encryptedResult = ModExp(plaintext, e, n);
    printf("加密结果为：%d", encryptedResult);
    printf("\n请输入密文：");
    int ciphertext;
    scanf("%d",&ciphertext);getchar();
    //解密
    int decryptedResult = ModExp(ciphertext, d, n);
    printf("解密结果为: %d\n", decryptedResult);
}
