//�α�ֲ���� 
#include"random.h"
void cursor_distribution_test() {
	extern int result[16];
	int e[RANDOM_LENGTH];//����e�Ľ��
	int k = 0;//��������e>=5�����������i 
	//����e��k 
	for(int i = 0; i < RANDOM_LENGTH; i++){
		e[i] = (RANDOM_LENGTH - i + 3)/(1 << (RANDOM_LENGTH + 2));
		if(e[i] >= 5){
			k = i;
		}
	}
	//��������γ̳��Ƚ�� 
	int b[k], g[k], length = 1;
	for(int i = 0; i < k; i++){
		b[i] = g[k] = 0;
	}
	for(int i = 0; i < RANDOM_LENGTH; i++){
		if(result[i+1] != result[i]){
			if(result[i] == 0){
				b[length]++;
			}else{
				g[length]++;
			}
		}else{
			length++;
			if(length > k){
				if(result[i] == 0){
					b[k-1]++;
				}else{
					g[k-1]++;
				}
				length = 0;
			}
		}
	}
	//����T
	int T = 0;
	for(int i = 0; i < k; i++){
		T += (b[i] + g[i]);
	}
	//����ei
	int ei[k];
	for(int i = 0; i < k; i++){
		if(i == k-1){
			ei[i] = T/(1 << (i + 1));
		}else{
			ei[i] = T/(1 << (i + 2));
		}
	}
	//����V
	double V = 0;
	for(int i = 0; i < k; i++){
		V += ((b[i] - ei[i]) * (b[i] - ei[i]) / ei[i] + (g[i] - ei[i]) * (g[i] - ei[i]) / ei[i]);
	}
	//����P_value, Q_value
	double P_value = 1.0 - tgamma(V / 2), Q_value = P_value;
	//�ж������
	if(P_value >= JUDGE_NUM){
		printf("��������ͨ������");
	}else{
		printf("��������δͨ������");
	} 
}



