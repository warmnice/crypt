#include"key.h"
//判断一个数是否为素数
bool isPrime(int a) {
	if (a <= 1) return false;
	if (a <= 3) return true;
	if (a % 2 == 0) return false;
	srand(time(NULL));
	//生成k值：[2, n-2] 
	int k = 2 + rand() % (a - 2 + 1);
	//将 a-1表示为 (2^r)*d，d为奇数
	int r = 0, d = a - 1;
	while (d % 2 == 0) {
		r++;
		d /= 2;
	} 
	//进行素性检测
	for (int i = 0; i < k; i++) {
		int witness = 2 + rand() % (a - 3);
		long long x = ModExp(witness, d, a);
		if (x == 1 || x == a - 1) continue;
		for (int j = 0; j < r - 1; j++){
			x = ModExp(x, 2, a);
			if(x == a - 1) break;
		}
		if (x != a - 1) return false;
	} 
	return true;
} 
