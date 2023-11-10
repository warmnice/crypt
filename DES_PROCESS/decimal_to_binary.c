//十进制转二进制，并求得s盒置换结果 
#include"des.h"
void decimal_to_binary(int index,int binary){
	extern int s_result[32];
	int result[4],num=0;
	while(binary){
		result[num++]=binary%2;
		binary/=2;
	}
	for(int i=0;i<4-num;i++){
		s_result[index*4+i]=0;
	}
	for(int i=0;i<num;i++){
		s_result[(index+1)*4-num+i]=result[num-1-i];
	}
}
