#include"key.h"
//RSA�㷨
void RSA(int p, int q){
    //����n��ŷ������m 
    int n = p * q;
    int m = (p - 1) * (q - 1);
    //ѡ��Կe
    int prime[m - 1 - 1];//������ܵĹ�Կ��� 
    int num = 0;//���ܵĹ�Կ���� 
    for (int i = 2; i < m ; i++) {
    	if(isPrime(i)) prime[num++] =  i; 
	}
	srand(time(NULL));
	int e = prime[rand() % num];
    //����˽Կd
    int d = 0;
    for (int i = 1; i < m; i++) {
        if ((i * e) % m == 1) {
            d = i;
            break;
        }
    }
    printf("���������ģ�");
    int plaintext;
    scanf("%d",&plaintext);getchar();
    //����
    int encryptedResult = ModExp(plaintext, e, n);
    printf("���ܽ��Ϊ��%d", encryptedResult);
    printf("\n���������ģ�");
    int ciphertext;
    scanf("%d",&ciphertext);getchar();
    //����
    int decryptedResult = ModExp(ciphertext, d, n);
    printf("���ܽ��Ϊ: %d\n", decryptedResult);
}
