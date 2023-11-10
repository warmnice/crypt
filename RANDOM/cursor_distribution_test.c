//游标分布检测 
#include"random.h"
void cursor_distribution_test() {
	extern int result[16];
	int e[RANDOM_LENGTH];//保存e的结果
	int k = 0;//保存满足e>=5的最大正整数i 
	//计算e和k 
	for(int i = 0; i < RANDOM_LENGTH; i++){
		e[i] = (RANDOM_LENGTH - i + 3)/(1 << (RANDOM_LENGTH + 2));
		if(e[i] >= 5){
			k = i;
		}
	}
	//保存各种游程长度结果 
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
	//计算T
	int T = 0;
	for(int i = 0; i < k; i++){
		T += (b[i] + g[i]);
	}
	//计算ei
	int ei[k];
	for(int i = 0; i < k; i++){
		if(i == k-1){
			ei[i] = T/(1 << (i + 1));
		}else{
			ei[i] = T/(1 << (i + 2));
		}
	}
	//计算V
	double V = 0;
	for(int i = 0; i < k; i++){
		V += ((b[i] - ei[i]) * (b[i] - ei[i]) / ei[i] + (g[i] - ei[i]) * (g[i] - ei[i]) / ei[i]);
	}
	//计算P_value, Q_value
	double P_value = 1.0 - tgamma(V / 2), Q_value = P_value;
	//判定检测结果
	if(P_value >= JUDGE_NUM){
		printf("待检序列通过检验");
	}else{
		printf("待检序列未通过检验");
	} 
}



