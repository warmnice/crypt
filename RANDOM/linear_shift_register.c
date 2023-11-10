//16位LSR生成随机序列
#include"random.h"
int linear_shift_register(){
	extern int seed;
	//连接多项式 
	int format[FORMAT] = {1, 1, 0, 0, 1};
	//保存异或结果 
	int result = seed << (FORMAT - 1);
	//LSR生成随机序列
	for(int i = 0; i < FORMAT - 1; i++){
		if(format[i] == 1){
			result ^= (seed << (FORMAT-i-2));
		}
    }
	return (seed = result);
}

