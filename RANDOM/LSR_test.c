//���LSR����������е������
#include"random.h"
void LSR_test(){
	extern int seed, result[RANDOM_LENGTH];
	//system("cls");
	printf("ʹ��%dλLSR�����������\n��ָ����������ӣ�", RANDOM_LENGTH);
	scanf("%d", &seed);getchar();
	//��LSR���ɵ�ʮ�����������ת��Ϊ�����ƽ����������������
	int temp = seed;
	for(int i = 0; i < RANDOM_LENGTH; i++){
		if(temp){
			result[FORMAT-1-i] = temp % 2;
			temp /= 2;
		}else{
			result[FORMAT-1-i] = 0;
		}
	} 
	int choice, index = 1;
	while(index == 1 || (choice > 0 && choice < 4)){
		printf("\n����Լ�ⷽ����\n1��������Ƶ�����\n2���α�ֲ����\n3������ؼ��\n��ѡ��");
		scanf("%d", &choice);
	    if(choice < 1 || choice >3){
	    	printf("������Ч...������ѡ��\n");
	    	index = 1;
	    	continue;
		}
		else{
			switch(choice){
				case 1: single_bit_frequency_test();break;
				case 2: cursor_distribution_test();break;
				case 3: autocorrelation_test();break;
			}
			printf("��ѡ���Ƿ�������... 0-NO 1-YES\n");
			scanf("%d", &index);getchar();
			if(index == 0) break;
		}
	}
} 

