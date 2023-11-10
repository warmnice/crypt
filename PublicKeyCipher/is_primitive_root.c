#include"key.h"
//�ж�һ�����Ƿ�Ϊԭ�� 
bool is_primitive_root(int g, int p) {
    //����ŷ������ 
    int m = p - 1;
    //�洢g���ݶ���ģp�Ľ��
    bool powers[m];
    //��ʼ��powers����Ϊfalse
    for (int i = 0; i < m; i++) {
        powers[i] = false;
    }
    //����g���ݲ��������ģp�Ľ�����Ϊtrue
    for (int i = 1; i <= m; i++) {
        int result = ModExp(g, i, p);
        powers[result - 1] = true;
    }
    //��������е�����Ԫ�ض�Ϊtrue����g��p��ԭ��
    for (int i = 0; i < m; i++) {
        if (!powers[i]) {
            return false;
        }
    }
    return true;
}
