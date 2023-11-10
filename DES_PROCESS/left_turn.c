//循环左移函数 
#include"des.h"
void left_turn(int index){
	extern int C[28],D[28];
  	if(index<2||index==8||index==15){
  		int temp1=C[0],temp2=D[0];//temp保存C,D的第一个元素
  		for(int i=0;i<27;i++){
  			C[i]=C[i+1];D[i]=D[i+1];
		}
		C[27]=temp1;D[27]=temp2;
	}else{
		int temp1[2],temp2[2];//temp保存C,D的前两个元素
		for(int i=0;i<2;i++){
			temp1[i]=C[i];temp2[i]=D[i];
		}
  		for(int i=0;i<26;i++){
  			C[i]=C[i+2];D[i]=D[i+2];
		}
		for(int i=0;i<2;i++){
			C[26+i]=temp1[i];D[26+i]=temp2[i];
		}
	}
}
