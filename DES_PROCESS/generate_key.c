//子密钥生成过程演示函数
#include"des.h"
void generate_key(){
	extern int key[64],replace1_c[28],replace1_d[28],replace2[48],real_key[56],keys[16][48],C[28],D[28];
	printf("密钥：");
	for(int i=0;i<64;i++){
		printf("%d",key[i]);
	}
	//置换选择1 
	printf("\n置换选择1：");
	//置换过程1之C0,D0
	printf("\nC0：");
	for(int i=0;i<28;i++){
	  C[i]=key[replace1_c[i]-1];
	  real_key[i]=C[i];
	  printf("%d",C[i]);
	  D[i]=key[replace1_d[i]-1];
	  real_key[i+28]=D[i];
	}
	printf("\nD0：");
	for(int i=0;i<28;i++){
	  printf("%d",D[i]);
	} 
	printf("\n真实密钥：");
	for(int i=0;i<56;i++){
		printf("%d",real_key[i]);
	}
	//置换过程2求解子密钥 
	for(int i=0;i<16;i++){
	    printf("\n\nN=%d",i+1);
		//循环左移更新C,D
	    left_turn(i);
	    //打印C,D 
	    printf("\nC%d：",i+1);
		for(int j=0;j<28;j++){
			printf("%d",C[j]);
		} 
		printf("\nD%d：",i+1);
		for(int j=0;j<28;j++){
			printf("%d",D[j]);
		} 
	    //根据置换矩阵求解子密钥并打印 
	    printf("\n子密钥K%d：",i+1);
	    for(int j=0;j<48;j++){
			if(replace2[j]>28){
				keys[i][j]=D[replace2[j]-29];
			}else{
				keys[i][j]=C[replace2[j]-1];	
		    }
		    printf("%d",keys[i][j]);
	    }
	}
} 
