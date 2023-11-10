//???????????? 
#include"des.h"
int binary_to_decimal(int *binary,int size){
	int num=1,result=0;
	for(int i=0;i<size;i++){
		result+=num*binary[size-1-i];
		num *= 2;
	}
	return result;
}
