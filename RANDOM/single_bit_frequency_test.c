//������Ƶ����� 
#include"random.h"
void single_bit_frequency_test(){
    extern int result[RANDOM_LENGTH];
    int X[RANDOM_LENGTH];//����X 
    int sum = 0;//����X��ͽ�� 
	//ת�������������0��1
	for(int i = 0; i <= RANDOM_LENGTH; i++){
		if(result[i] == 0) result[i] = -1;
		X[i] = 2 * result[i] - 1; 
		sum += X[i];
	} 
	//����ͳ��ֵ
	double V = sum / sqrt(RANDOM_LENGTH);
	//����P_value��Q_value
	double P_value = 1.0 - erf(V / sqrt(2));
	double Q_value = 0.5 * P_value;
	//�ж������
	if(P_value >= JUDGE_NUM){
		printf("��������ͨ������\n");
	}else{
		printf("��������δͨ������\n");
	}
}

