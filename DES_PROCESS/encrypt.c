//���ܺ��� 
#include"des.h"
void encrypt(){
	extern int L[32],R[32],out_table[48],keys[16][48],plaintext[64],IP_reset[64],IP_inverse[64],
			   S[8][4][16],P[32],f_result[32],ciphertext[64],add_result[48],s_result[32];
	//��ӡ����
	printf("\n\n���ģ�");
	for(int i=0;i<64;i++){
		printf("%d",plaintext[i]);
	} 
	//��ʼ�û�IP 
	printf("\n��ʼ�û���");
	int temp_plaintext[64];
	for(int i=0;i<64;i++){
		temp_plaintext[i]=plaintext[IP_reset[i]-1];
		printf("%d",temp_plaintext[i]);
	}
	printf("\nL0��");
	for(int i=0;i<32;i++){
		L[i]=temp_plaintext[i];
		printf("%d",L[i]);
	}
	printf("\nR0��"); 
	for(int i=0;i<32;i++){
		R[i]=temp_plaintext[32+i];
		printf("%d",R[i]);
	}
	//16�ּ��� 
	for(int i=0;i<16;i++){
		printf("\n\nN=%d",i+1);
		printf("\nF������\n32λ���룺");
		for(int j=0;j<32;j++) printf("%d",R[j]);
		printf("\nѡ�����㣨��չR����");
		int temp_r[48];
		for(int j=0;j<48;j++){
			temp_r[j]=R[out_table[j]-1];
			printf("%d",temp_r[j]);
		}
		//��ӡ����Կ 
		printf("\n����ԿK%d��",i+1);
		for(int j=0;j<48;j++){
			printf("%d",keys[i][j]);
		}
		//��ӡ����Կ��R�����ӵĽ�� 
		printf("\n����Կ�ӣ�");
		for(int j=0;j<48;j++){
			if(temp_r[j]==keys[i][j]){
				add_result[j]=0;
			}else{
				add_result[j]=1;
			}
			printf("%d",add_result[j]);
		}
		//S���û� 
	    for(int j=0;j<8;j++){
		    int line_array[2]={add_result[j*6],add_result[(j+1)*6-1]};
		    int column_array[4]={add_result[j*6+1],add_result[j*6+2],add_result[j*6+3],add_result[j*6+4]};
		    int line=binary_to_decimal(line_array,2);
		    int column=binary_to_decimal(column_array,4);
		    int binary=S[j][line][column];
		    decimal_to_binary(j,binary);
    	}
	    //��ӡS���û����
	    printf("\nS���û������");
	    for(int j=0;j<32;j++){
		    printf("%d",s_result[j]);
	    } 
		//P���û�����ӡ���
		int temp_R[32];
		for(int j=0;j<32;j++){
			temp_R[j]=R[j];//����ԭ����R 
		}
		printf("\nP�û���",i+1);
		for(int j=0;j<32;j++){
			f_result[j]=s_result[P[j]-1];
			if(f_result[j]==L[j]){
				R[j]=0;
			}else{
				R[j]=1;
			}
			printf("%d",f_result[j]);
		}
		printf("\nL%d��",i+1);
        if(i<15){
        	//��ӡ���ּ����õ�L��������L��������һ�ּ��� 
	    	for(int j=0;j<32;j++){
			   L[j]=temp_R[j]; 
		  	   printf("%d",L[j]);
	        }
	        //��ӡ���ּ����õ�R
	        printf("\nR%d��",i+1);
	        for(int j=0;j<32;j++){
		       printf("%d",R[j]);
	        } 		
		}else{
			//���һ��Ҫ����L,R
	    	for(int j=0;j<32;j++){
			   L[j]=R[j]; 
		  	   printf("%d",L[j]);
	        }
	        //��ӡ���ּ����õ�R
	        printf("\nR%d��",i+1);
	        for(int j=0;j<32;j++){
	           R[j]=temp_R[j];
		       printf("%d",R[j]);
	        } 		
		}
	}
	//���ʼ�û������Ĳ���ӡ
	printf("\n���ʼ�û�������ģ�"); 
	for(int i=0;i<64;i++){
		if(IP_inverse[i]>32){
			ciphertext[i]=R[IP_inverse[i]-33];	
		}else{
			ciphertext[i]=L[IP_inverse[i]-1];	
		}
		printf("%d",ciphertext[i]);
	}
}
