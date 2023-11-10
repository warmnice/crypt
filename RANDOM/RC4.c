//RC4��̣��۲�I,J�仯
#include"random.h" 
void RC4(){
	int S[RC4_S_LENGTH], R[RC4_S_LENGTH];
	char key[KEY_S_LENGTH] = "four4five5crypt6";//����������Կ 
	//��ʼ��S��
	for(int i = 0; i < RC4_S_LENGTH; i++){
		S[i] = i;
	}
	//��������Կ���R��
	int i = 0, j = 0;
	while(i < RC4_S_LENGTH){
		R[i++] = key[j++];
		if(j == KEY_S_LENGTH) j = 0;
	}
	//��R���S��������Դ�������ӡI��J�ı仯 
	printf("\n I    J\n");
	for(int I = 0; I < RC4_S_LENGTH; I++){
		int J = (J + S[I] + R[I]) % RC4_S_LENGTH;
		printf("\n %d   %d\n", I, J);
		swap(&S[I], &S[J]);
	}
	//����256����Կ���У�������256��ͬһ�������ֽ� 
	int I =0, J = 0;
	//��ʼ������
	int PLAINTEXT[MAX_KEY_LEANTH] = {0,1,0,1,1,0,0,0}; 
	printf("\n�������У�01011000");
	printf("\n�ڼ��μ���    ��Կ       ���ܽ��"); 
	while(I < RC4_S_LENGTH){
		J = (J + S[I]) % RC4_S_LENGTH;
		swap(&S[I], &S[J]);
		int H = (S[I] + S[J]) % RC4_S_LENGTH;
		//������Կ������S[]��ΧΪ0-255�����key�Ķ������λ�����ᳬ��8 
		int key = S[H];
		//��ʮ���Ƶ���Կ��Ϊ�����Ʋ����浽temp_key������
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

