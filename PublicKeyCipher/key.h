#include"stdio.h"
#include"stdbool.h"
#include"stdlib.h"
#include"time.h" 
// ģָ����
int ModExp(int b, int n, int m);
// �ж�һ�����Ƿ�Ϊ����
bool isPrime(int a);
// DH��Կ����Э��
void DH(int p, int g, int a, int b);
// ELGamal�㷨
void ELGamal(int p, int *g_temp, int num);
// RSA�㷨
void RSA(int p, int q); 
//�ж�һ�����Ƿ�Ϊԭ�� 
bool is_primitive_root(int g, int p);
