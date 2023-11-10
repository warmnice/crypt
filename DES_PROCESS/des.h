#include"stdio.h"

//子密钥生成过程演示函数
void generate_key(); 
//加密函数
void encrypt();
//S盒置换
void s_replace(); 
//循环左移函数
void left_turn(int index); 
//二进制转十进制
int binary_to_decimal(int *binary,int size); 
//十进制转二进制，并求得s盒置换结果  
void decimal_to_binary(int index,int binary); 
