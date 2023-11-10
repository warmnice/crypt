#include"key.h"
//模指运算 
int ModExp(int b, int n, int m) {
 	//模数为1，结果为0 
 	if(m == 1) return 0;
 	int result = 1;//记录快速算法的计算结果 
 	b = b % m;//将底数对模数取余
	while (n > 0) {
		//如果指数为奇数，将当前结果乘以底数并对模数取余
		if(n % 2) {
			result = (result * b) % m;
		} 
		//将底数平方并对模数取余，指数减半
		b = (b * b) % m;
		n /= 2; 
	} 
	return result;
}
