//检测LSR生成随机序列的随机性
#include"random.h"
void LSR_test(){
	extern int seed, result[RANDOM_LENGTH];
	//system("cls");
	printf("使用%d位LSR生成随机序列\n请指定随机数种子：", RANDOM_LENGTH);
	scanf("%d", &seed);getchar();
	//将LSR生成的十进制随机序列转换为二进制结果并保存在数组中
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
		printf("\n随机性检测方法：\n1、单比特频数检测\n2、游标分布检测\n3、自相关检测\n请选择：");
		scanf("%d", &choice);
	    if(choice < 1 || choice >3){
	    	printf("输入无效...请重新选择\n");
	    	index = 1;
	    	continue;
		}
		else{
			switch(choice){
				case 1: single_bit_frequency_test();break;
				case 2: cursor_distribution_test();break;
				case 3: autocorrelation_test();break;
			}
			printf("请选择是否继续检测... 0-NO 1-YES\n");
			scanf("%d", &index);getchar();
			if(index == 0) break;
		}
	}
} 

