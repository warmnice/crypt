#include"key.h"
//ģָ���� 
int ModExp(int b, int n, int m) {
 	//ģ��Ϊ1�����Ϊ0 
 	if(m == 1) return 0;
 	int result = 1;//��¼�����㷨�ļ����� 
 	b = b % m;//��������ģ��ȡ��
	while (n > 0) {
		//���ָ��Ϊ����������ǰ������Ե�������ģ��ȡ��
		if(n % 2) {
			result = (result * b) % m;
		} 
		//������ƽ������ģ��ȡ�ָ࣬������
		b = (b * b) % m;
		n /= 2; 
	} 
	return result;
}
