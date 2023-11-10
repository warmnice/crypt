//加密函数 
#include"des.h"
void encrypt(){
	extern int L[32],R[32],out_table[48],keys[16][48],plaintext[64],IP_reset[64],IP_inverse[64],
			   S[8][4][16],P[32],f_result[32],ciphertext[64],add_result[48],s_result[32];
	//打印明文
	printf("\n\n明文：");
	for(int i=0;i<64;i++){
		printf("%d",plaintext[i]);
	} 
	//初始置换IP 
	printf("\n初始置换：");
	int temp_plaintext[64];
	for(int i=0;i<64;i++){
		temp_plaintext[i]=plaintext[IP_reset[i]-1];
		printf("%d",temp_plaintext[i]);
	}
	printf("\nL0：");
	for(int i=0;i<32;i++){
		L[i]=temp_plaintext[i];
		printf("%d",L[i]);
	}
	printf("\nR0："); 
	for(int i=0;i<32;i++){
		R[i]=temp_plaintext[32+i];
		printf("%d",R[i]);
	}
	//16轮加密 
	for(int i=0;i<16;i++){
		printf("\n\nN=%d",i+1);
		printf("\nF函数：\n32位输入：");
		for(int j=0;j<32;j++) printf("%d",R[j]);
		printf("\n选择运算（扩展R）：");
		int temp_r[48];
		for(int j=0;j<48;j++){
			temp_r[j]=R[out_table[j]-1];
			printf("%d",temp_r[j]);
		}
		//打印子密钥 
		printf("\n子密钥K%d：",i+1);
		for(int j=0;j<48;j++){
			printf("%d",keys[i][j]);
		}
		//打印子密钥与R做异或加的结果 
		printf("\n子密钥加：");
		for(int j=0;j<48;j++){
			if(temp_r[j]==keys[i][j]){
				add_result[j]=0;
			}else{
				add_result[j]=1;
			}
			printf("%d",add_result[j]);
		}
		//S盒置换 
	    for(int j=0;j<8;j++){
		    int line_array[2]={add_result[j*6],add_result[(j+1)*6-1]};
		    int column_array[4]={add_result[j*6+1],add_result[j*6+2],add_result[j*6+3],add_result[j*6+4]};
		    int line=binary_to_decimal(line_array,2);
		    int column=binary_to_decimal(column_array,4);
		    int binary=S[j][line][column];
		    decimal_to_binary(j,binary);
    	}
	    //打印S盒置换结果
	    printf("\nS盒置换结果：");
	    for(int j=0;j<32;j++){
		    printf("%d",s_result[j]);
	    } 
		//P盒置换并打印结果
		int temp_R[32];
		for(int j=0;j<32;j++){
			temp_R[j]=R[j];//保存原来的R 
		}
		printf("\nP置换：",i+1);
		for(int j=0;j<32;j++){
			f_result[j]=s_result[P[j]-1];
			if(f_result[j]==L[j]){
				R[j]=0;
			}else{
				R[j]=1;
			}
			printf("%d",f_result[j]);
		}
		printf("\nL%d：",i+1);
        if(i<15){
        	//打印本轮加密用的L，并更新L以用于下一轮加密 
	    	for(int j=0;j<32;j++){
			   L[j]=temp_R[j]; 
		  	   printf("%d",L[j]);
	        }
	        //打印本轮加密用的R
	        printf("\nR%d：",i+1);
	        for(int j=0;j<32;j++){
		       printf("%d",R[j]);
	        } 		
		}else{
			//最后一轮要交换L,R
	    	for(int j=0;j<32;j++){
			   L[j]=R[j]; 
		  	   printf("%d",L[j]);
	        }
	        //打印本轮加密用的R
	        printf("\nR%d：",i+1);
	        for(int j=0;j<32;j++){
	           R[j]=temp_R[j];
		       printf("%d",R[j]);
	        } 		
		}
	}
	//逆初始置换得密文并打印
	printf("\n逆初始置换后的密文："); 
	for(int i=0;i<64;i++){
		if(IP_inverse[i]>32){
			ciphertext[i]=R[IP_inverse[i]-33];	
		}else{
			ciphertext[i]=L[IP_inverse[i]-1];	
		}
		printf("%d",ciphertext[i]);
	}
}
