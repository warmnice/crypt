#include"random.h"
int seed;//LSR���� 
int leftto_new[16];//��ʼ���� 
int result[16];//LSR���ɵ�������ж����ƽ�� 
int main(void){
	printf("ϵͳ����ʵ�֣�\n1�����LSR���ɵ���������������\n2���۲�RC4������I��J�ı仯����\n3������hash����Ѱ�ұ���Ӳ���ظ��ļ�\n");
	int input, index = 0;
	while(index = 1 || input > 0 && input < 4){
		printf("\n��ѡ����Ҫʵ�ֵĹ��ܣ�");
		scanf("%d", &input);getchar();
		if(input < 1 || input >3){
			printf("������Ч...������ѡ��\n");
			index = 1;
			continue;
		}else{
			switch(input){
				case 1: LSR_test();break;
				case 2: RC4();break;
				case 3: hash();break;
			}
			printf("\n��ѡ���Ƿ��˳�ϵͳ... 1-NO else-YES\n");
			scanf("%d", &index);getchar();
			if(index == 1) continue;
			else break;
		}
	}
	return 0;
}

