//S盒验证 
#include"des.h"
void s_replace(){
	extern int S[8][4][16];
	int add_result[48],s_result[32];
	printf("\n\nS盒验证：\n输入：");
	for(int i=0;i<48;i++){
		//add_result[i]=0;
		add_result[i]=1;
		if((i+1)%6==0) add_result[i]=0;
		printf("%d",add_result[i]);
	}
	for(int j=0;j<8;j++){
		int line_array[2]={add_result[j*6],add_result[(j+1)*6-1]};
		int column_array[4]={add_result[j*6+1],add_result[j*6+2],add_result[j*6+3],add_result[j*6+4]};
		int line=binary_to_decimal(line_array,2);
		int column=binary_to_decimal(column_array,4);
		int binary=S[j][line][column];
		decimal_to_binary(j,binary);
	}
	//打印S盒置换结果
	printf("\n输出：");
	for(int j=0;j<32;j++){
		printf("%d",s_result[j]);
	} 
} 
