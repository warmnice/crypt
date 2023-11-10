#include"key.h"
//�ж�һ�����Ƿ�Ϊ����
bool isPrime(int a) {
	if (a <= 1) return false;
	if (a <= 3) return true;
	if (a % 2 == 0) return false;
	srand(time(NULL));
	//����kֵ��[2, n-2] 
	int k = 2 + rand() % (a - 2 + 1);
	//�� a-1��ʾΪ (2^r)*d��dΪ����
	int r = 0, d = a - 1;
	while (d % 2 == 0) {
		r++;
		d /= 2;
	} 
	//�������Լ��
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
