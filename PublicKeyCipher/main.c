#include"key.h"
int main(void){
	printf("系统功能实现：\n1、模指运算\n2、判断一个数是否为素数\n3、DH密钥交换协议\n4、ElGamal算法\n5、RSA算法\n");
	int input, index = 0;
	while(index = 1 || input > 0 && input < 6){
		printf("\n请选择你要实现的功能：");
		scanf("%d", &input);getchar();
		if(input < 1 || input > 5){
			printf("输入无效...请重新选择\n");
			index = 1;
			continue;
		}else{
			switch(input){
				case 1: {
					printf("\n模指运算b^n mod m...请按照类似于1,2,3的形式依次输入b,n,m：");
					int b,n,m;
					scanf("%d,%d,%d",&b,&n,&m);getchar();
					printf("计算结果：%d",ModExp(b,n,m));
					break;
				}
				case 2: {
					printf("判断一个数是否为素数，你想判断的数是：");
					int a;
					scanf("%d",&a);getchar();
					printf("判断结果：%d",a);
					if(isPrime(a)) printf("是素数");
					else printf("不是素数");
					break;
				}
				case 3: {
					printf("\n请按照类似于23,5的形式输入两个大素数[后者为前者原根]：");
					int p, g, a, b;
					do {
						scanf("%d,%d", &p, &g);getchar();
						
						if(!(isPrime(p) && isPrime(g)) || (p <=3 && g <= 3) || !is_primitive_root(g,p)) 
							printf("\n输入不是素数 或 输入太小 或 后者不是前者的原根...请尝试重新输入：");
						else {
							do{
								printf("请选择私钥\n小明：");scanf("%d", &a);getchar();
								printf("小灰：");scanf("%d", &b);getchar();
								if(a <=0 || b <=0 || a > p || a >= p || b >= p){
									printf("私钥选择不能是非正数且要小于p..请重新选择：\n");
								}else break;
							}while(1);
							DH(p, g, a, b);
							break;
						}
					} while(1);
					break;
				}
				case 4: {
					printf("请输入一个大素数p：");
					int p;
					bool judge = false;//记录p-1是否有大素数因子 
					do {
						scanf("%d", &p);getchar();
						for (int i = 5; i < p - 1; i++){
							if (isPrime(i)) {
								judge = true; break;
							}
						}
						int g_temp[p - 2];//素数p所有的原根 
						int num = 0;//p的原根数量 
						for (int i = 1; i < p; i++) {
							if (is_primitive_root(i, p)) {
								g_temp[num++] = i;
							}
						}
						if(!isPrime(p) || num == 0 || !judge)
							printf("\n输入不是素数 或 p没有原根 或 p-1没有大素数因子..请尝试重新输入：");
						else {
							ELGamal(p, g_temp, num);break;
						}	
					} while(1);
					break;
				}
				case 5: {
					printf("\n请按照类似于11,19的形式输入两个大素数：");
					int p, q;
					do {
						scanf("%d,%d", &p, &q);getchar();
						if(!(isPrime(p) && isPrime(q)) || (p <=3 && q <= 3)) 
							printf("\n输入不是素数 或 输入太小...请尝试重新输入：");
						else {
							RSA(p, q); break;
						}
					} while(1);
					break;
				}
			}
			printf("\n请选择是否退出系统... 1-NO else-YES\n");
			scanf("%d", &index);getchar();
			if(index == 1) continue;
			else break;
		}
	}
	return 0;
}
