//单比特频数检测 
#include"random.h"
void single_bit_frequency_test(){
    extern int result[RANDOM_LENGTH];
    int X[RANDOM_LENGTH];//保存X 
    int sum = 0;//保存X求和结果 
	//转化待检序列里的0和1
	for(int i = 0; i <= RANDOM_LENGTH; i++){
		if(result[i] == 0) result[i] = -1;
		X[i] = 2 * result[i] - 1; 
		sum += X[i];
	} 
	//计算统计值
	double V = sum / sqrt(RANDOM_LENGTH);
	//计算P_value和Q_value
	double P_value = 1.0 - erf(V / sqrt(2));
	double Q_value = 0.5 * P_value;
	//判定检测结果
	if(P_value >= JUDGE_NUM){
		printf("待检序列通过检验\n");
	}else{
		printf("待检序列未通过检验\n");
	}
}

