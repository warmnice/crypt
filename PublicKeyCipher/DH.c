#include "key.h"
// DH��Կ����Э��
void DH(int p, int g, int a, int b)
{
    // ����С���Ĺ�ԿA
    int A = ModExp(g, a, p);
    // ����С�ҵĹ�ԿB
    int B = ModExp(g, b, p);
    // С����С�ҽ������ԵĹ�Կ�����㹲����Կ
    int sharedKeyA = ModExp(B, a, p);
    int sharedKeyB = ModExp(A, b, p);
    printf("С���Ĺ�����Կ: %d\n", sharedKeyA);
    printf("С�ҵĹ�����Կ: %d\n", sharedKeyB);
}
