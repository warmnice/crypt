//RC4编程，观察I,J变化
#include"random.h" 
void RC4(){
	int S[RC4_S_LENGTH], R[RC4_S_LENGTH];
	char key[KEY_S_LENGTH] = "four4five5crypt6";//保存种子密钥 
	//初始化S表
	for(int i = 0; i < RC4_S_LENGTH; i++){
		S[i] = i;
	}
	//用种子密钥填充R表
	int i = 0, j = 0;
	while(i < RC4_S_LENGTH){
		R[i++] = key[j++];
		if(j == KEY_S_LENGTH) j = 0;
	}
	//用R表对S进行随机性处理，并打印I、J的变化 
	printf("\n I    J\n");
	for(int I = 0; I < RC4_S_LENGTH; I++){
		int J = (J + S[I] + R[I]) % RC4_S_LENGTH;
		printf("\n %d   %d\n", I, J);
		swap(&S[I], &S[J]);
	}
	//生成256个密钥序列，并加密256次同一个明文字节 
	int I =0, J = 0;
	//初始化明文
	int PLAINTEXT[MAX_KEY_LEANTH] = {0,1,0,1,1,0,0,0}; 
	printf("\n明文序列：01011000");
	printf("\n第几次加密    密钥       加密结果"); 
	while(I < RC4_S_LENGTH){
		J = (J + S[I]) % RC4_S_LENGTH;
		swap(&S[I], &S[J]);
		int H = (S[I] + S[J]) % RC4_S_LENGTH;
		//产生密钥，由于S[]范围为0-255，因此key的二进制最长位数不会超过8 
		int key = S[H];
		//将十进制的密钥换为二进制并保存到temp_key数组里
		int temp_key[MAX_KEY_LEANTH], temp = key;
		for(int i = 0; i < MAX_KEY_LEANTH; i++){
			if(temp){
				temp_key[MAX_KEY_LEANTH - 1 - i] = temp % 2;
				temp /= 2;	
			}else{
				temp_key[MAX_KEY_LEANTH - 1 - i] = 0;
			}
		}
		printf("\n   %d       ", ++I);
		if(I < 10 ) printf("  ");
		else if(I < 100) printf(" "); 
		for(int i = 0; i < MAX_KEY_LEANTH; i++){
			printf("%d", temp_key[i]);
		}
		printf("      ");
		for(int i = 0; i < MAX_KEY_LEANTH; i++){
			if(temp_key[i] == PLAINTEXT[i]) printf("0");
			else printf("1");
		}
	}
}

