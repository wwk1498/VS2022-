#include<iostream>
using namespace std;

//쳲��������У�F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12)
//                          0      1    1      2     3    5      8      13   21   34    55     89    144

//����---->������ú����Ĵ���: 2*f(n+1)-1
//f(3)----->5
//f(4)----->9
//f(5)----->15


//�ݹ���쳲��������е�ʱ�临�Ӷȣ�O-(1.618n�η�)

//ʹ��   �ݹ�--β����  ------> ���Ա��ⱬջ
int fun(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fun(n - 1) + fun(n - 2);
}

//�Ż�쳲���������----���䷨   ʱ�临�Ӷ� O(n)
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

//��ֹβ�ݹ鱬ջ����-->�ݹ�ʵ�ֽ׳�
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
