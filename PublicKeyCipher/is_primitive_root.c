#include"key.h"
//判断一个数是否为原根 
bool is_primitive_root(int g, int p) {
    //计算欧拉函数 
    int m = p - 1;
    //存储g的幂对于模p的结果
    bool powers[m];
    //初始化powers数组为false
    for (int i = 0; i < m; i++) {
        powers[i] = false;
    }
    //计算g的幂并将其对于模p的结果标记为true
    for (int i = 1; i <= m; i++) {
        int result = ModExp(g, i, p);
        powers[result - 1] = true;
    }
    //如果数组中的所有元素都为true，则g是p的原根
    for (int i = 0; i < m; i++) {
        if (!powers[i]) {
            return false;
        }
    }
    return true;
}
