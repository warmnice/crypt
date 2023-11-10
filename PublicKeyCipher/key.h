#include"stdio.h"
#include"stdbool.h"
#include"stdlib.h"
#include"time.h" 
// 模指运算
int ModExp(int b, int n, int m);
// 判断一个数是否为素数
bool isPrime(int a);
// DH密钥交换协议
void DH(int p, int g, int a, int b);
// ELGamal算法
void ELGamal(int p, int *g_temp, int num);
// RSA算法
void RSA(int p, int q); 
//判断一个数是否为原根 
bool is_primitive_root(int g, int p);
