#include"random.h"
int seed;//LSR种子 
int leftto_new[16];//初始序列 
int result[16];//LSR生成的随机序列二进制结果 
int main(void){
	printf("系统功能实现：\n1、检测LSR生成的随机序列其随机性\n2、观察RC4密码里I、J的变化规律\n3、利用hash函数寻找本地硬盘重复文件\n");
	int input, index = 0;
	while(index = 1 || input > 0 && input < 4){
		printf("\n请选择你要实现的功能：");
		scanf("%d", &input);getchar();
		if(input < 1 || input >3){
			printf("输入无效...请重新选择\n");
			index = 1;
			continue;
		}else{
			switch(input){
				case 1: LSR_test();break;
				case 2: RC4();break;
				case 3: hash();break;
			}
			printf("\n请选择是否退出系统... 1-NO else-YES\n");
			scanf("%d", &index);getchar();
			if(index == 1) continue;
			else break;
		}
	}
	return 0;
}

