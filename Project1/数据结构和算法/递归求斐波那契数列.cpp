#include<iostream>
using namespace std;

//斐波那契数列：F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12)
//                          0      1    1      2     3    5      8      13   21   34    55     89    144

//函数---->整体调用函数的次数: 2*f(n+1)-1
//f(3)----->5
//f(4)----->9
//f(5)----->15


//递归求斐波那契数列的时间复杂度：O-(1.618n次方)

//使用   递归--尾调用  ------> 可以避免爆栈
int fun(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fun(n - 1) + fun(n - 2);
}

//优化斐波那契数列----记忆法   时间复杂度 O(n)
int fibonacci(int n) {
	//int fib[n+1];
	int *fib = (int *)malloc(sizeof(int) * (n + 1));
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}

//防止尾递归爆栈问题-->递归实现阶乘
int factorial_iter(int n, int result) {
	if (n == 0) {
		return result;
	}
	else {
		return factorial_iter(n - 1, n * result);
	}
}

int factorial(int n) {
	return factorial_iter(n, 1);
}




int main(void) {
	cout << fun(12) << "  ";
	cout << fibonacci(12) << "  ";
	cout << factorial(3) << "  ";
	system("pause");
	return 0;
}
