#include"key.h"
// ELGamal�㷨
void ELGamal(int p, int *g_temp, int num){
	//���ѡ��ԭ��g
	srand(time(NULL));
	int g = g_temp[rand() % num]; 
	//�������˽Կx
    int x = 2 + rand() % (p - 3);  //˽Կx
    //���ѡȡ����k 
    int k = 2 + rand() % (p - 3);
    //���㹫Կy
    int y = ModExp(g, x, p);
    printf("\n���������ģ�");
    int plaintext;
    scanf("%d",&plaintext);getchar();
    //����
    int encryptedResult = (plaintext * ModExp(y, k, p)) % p;
    printf("���ܽ��Ϊ��%d", encryptedResult);
    int a = ModExp(g, k, p);
    printf("\n���������ģ�");
    int ciphertext;
    scanf("%d",&ciphertext);getchar();
    //����
    int decryptedResult = (ciphertext * ModExp(a, p - 1 - x, p)) % p;
    printf("���ܽ��Ϊ: %d\n", decryptedResult);
}
