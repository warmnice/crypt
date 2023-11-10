// ����ؼ��
#include "random.h"
void autocorrelation_test()
{
	extern int leftto_new[RANDOM_LENGTH], result[RANDOM_LENGTH];
	// ����A(d),ȡd=4
	int A = 0;
	for (int i = 0; i < RANDOM_LENGTH; i++)
	{
		// ȷ�����ƺ�������в�����
		if (i < RANDOM_LENGTH - D)
			leftto_new[i] = result[i + D];
		else
			leftto_new[i] = 0;
		if (result[i] == leftto_new[i])
			A += 0;
		else
			A += 1;
	}
	// ����ͳ��ֵ
	double V = (2 * (A - (RANDOM_LENGTH - D) / 2)) / sqrt(RANDOM_LENGTH - D);
	// ����P_value��Q_value
	double P_value = 1.0 - erf(V / sqrt(2));
	double Q_value = 0.5 * P_value;
	// �ж������
	if (P_value >= JUDGE_NUM)
	{
		printf("��������ͨ������");
	}
	else
	{
		printf("��������δͨ������");
	}
}
