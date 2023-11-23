/*

1.runtime_error������ʱ�쳣�����ڳ����߼�������Ч�Ĳ���������Ԥ��������
2.logic_error�����ڱ�ʾ�߼���������Ч�Ĳ����������
3.invalid_argument�����ڱ�ʾ���ݸ������Ĳ�����Ч��
4.domain_error�����ڱ�ʾ������ֵ��������Ч�Ķ�����
5.length_error�����ڱ�ʾ���Ȼ�������С�����˿��÷�Χ��
6.out_of_range�����ڱ�ʾ�������������������Ч��Χ��
7.overflow_error�����ڱ�ʾ�������������������������ܹ����ɵķ�Χ��
8.underflow_error�����ڱ�ʾ�����������������������ܹ����ɵķ�Χ��


*/







#include <iostream>
using namespace std;
void divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("��������Ϊ��");
    }
    std::cout << "a / b = " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    }
    catch (const std::exception& e) {
        std::cout << "�����쳣��" << e.what() << std::endl;
    }
    system("pause");
    return 0;
}