#include"key.h"
int main(void){
	printf("ϵͳ����ʵ�֣�\n1��ģָ����\n2���ж�һ�����Ƿ�Ϊ����\n3��DH��Կ����Э��\n4��ElGamal�㷨\n5��RSA�㷨\n");
	int input, index = 0;
	while(index = 1 || input > 0 && input < 6){
		printf("\n��ѡ����Ҫʵ�ֵĹ��ܣ�");
		scanf("%d", &input);getchar();
		if(input < 1 || input > 5){
			printf("������Ч...������ѡ��\n");
			index = 1;
			continue;
		}else{
			switch(input){
				case 1: {
					printf("\nģָ����b^n mod m...�밴��������1,2,3����ʽ��������b,n,m��");
					int b,n,m;
					scanf("%d,%d,%d",&b,&n,&m);getchar();
					printf("��������%d",ModExp(b,n,m));
					break;
				}
				case 2: {
					printf("�ж�һ�����Ƿ�Ϊ�����������жϵ����ǣ�");
					int a;
					scanf("%d",&a);getchar();
					printf("�жϽ����%d",a);
					if(isPrime(a)) printf("������");
					else printf("��������");
					break;
				}
				case 3: {
					printf("\n�밴��������23,5����ʽ��������������[����Ϊǰ��ԭ��]��");
					int p, g, a, b;
					do {
						scanf("%d,%d", &p, &g);getchar();
						
						if(!(isPrime(p) && isPrime(g)) || (p <=3 && g <= 3) || !is_primitive_root(g,p)) 
							printf("\n���벻������ �� ����̫С �� ���߲���ǰ�ߵ�ԭ��...�볢���������룺");
						else {
							do{
								printf("��ѡ��˽Կ\nС����");scanf("%d", &a);getchar();
								printf("С�ң�");scanf("%d", &b);getchar();
								if(a <=0 || b <=0 || a > p || a >= p || b >= p){
									printf("˽Կѡ�����Ƿ�������ҪС��p..������ѡ��\n");
								}else break;
							}while(1);
							DH(p, g, a, b);
							break;
						}
					} while(1);
					break;
				}
				case 4: {
					printf("������һ��������p��");
					int p;
					bool judge = false;//��¼p-1�Ƿ��д��������� 
					do {
						scanf("%d", &p);getchar();
						for (int i = 5; i < p - 1; i++){
							if (isPrime(i)) {
								judge = true; break;
							}
						}
						int g_temp[p - 2];//����p���е�ԭ�� 
						int num = 0;//p��ԭ������ 
						for (int i = 1; i < p; i++) {
							if (is_primitive_root(i, p)) {
								g_temp[num++] = i;
							}
						}
						if(!isPrime(p) || num == 0 || !judge)
							printf("\n���벻������ �� pû��ԭ�� �� p-1û�д���������..�볢���������룺");
						else {
							ELGamal(p, g_temp, num);break;
						}	
					} while(1);
					break;
				}
				case 5: {
					printf("\n�밴��������11,19����ʽ����������������");
					int p, q;
					do {
						scanf("%d,%d", &p, &q);getchar();
						if(!(isPrime(p) && isPrime(q)) || (p <=3 && q <= 3)) 
							printf("\n���벻������ �� ����̫С...�볢���������룺");
						else {
							RSA(p, q); break;
						}
					} while(1);
					break;
				}
			}
			printf("\n��ѡ���Ƿ��˳�ϵͳ... 1-NO else-YES\n");
			scanf("%d", &index);getchar();
			if(index == 1) continue;
			else break;
		}
	}
	return 0;
}
