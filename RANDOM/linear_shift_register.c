//16λLSR�����������
#include"random.h"
int linear_shift_register(){
	extern int seed;
	//���Ӷ���ʽ 
	int format[FORMAT] = {1, 1, 0, 0, 1};
	//��������� 
	int result = seed << (FORMAT - 1);
	//LSR�����������
	for(int i = 0; i < FORMAT - 1; i++){
		if(format[i] == 1){
			result ^= (seed << (FORMAT-i-2));
		}
    }
	return (seed = result);
}

