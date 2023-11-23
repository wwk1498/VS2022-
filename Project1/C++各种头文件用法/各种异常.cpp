/*

1.runtime_error：运行时异常，由于程序逻辑错误、无效的操作或不满足预期条件等
2.logic_error：用于表示逻辑错误，如无效的参数或操作。
3.invalid_argument：用于表示传递给函数的参数无效。
4.domain_error：用于表示参数的值超出了有效的定义域。
5.length_error：用于表示长度或容器大小超出了可用范围。
6.out_of_range：用于表示索引或迭代器超出了有效范围。
7.overflow_error：用于表示算术运算结果超出了数据类型能够容纳的范围。
8.underflow_error：用于表示算术运算结果低于数据类型能够容纳的范围。


*/







#include <iostream>
using namespace std;
void divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("除数不能为零");
    }
    std::cout << "a / b = " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    }
    catch (const std::exception& e) {
        std::cout << "捕获到异常：" << e.what() << std::endl;
    }
    system("pause");
    return 0;
}