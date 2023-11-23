#include<iostream>
using namespace std;

class person {
	friend ostream& operator<<(ostream& cout, const person& p);
private :
	int a;
public:
	person() {
		a = 0;
	}

	person& operator++() {//前置递增，返回为person是返回其副本，不是本体，返回为person&，是返回本体的别名，可以对本体进行修改
		a++;
		return *this;
	}

	person operator++(int) {//后置递增
		person temp = *this;//局部变量，函数调用完，自动销毁
		a++;
		return temp;//返回
	}

};

  /*void operator<<(ostream& cout, person& p) {
	cout << p.a << "  " << p.b<<endl;
}*/

ostream& operator<<(ostream &cout, const person &p) {
	cout << p.a << endl;
	return cout;
}


void test01() {
	person p1;
	
	cout << ++(++p1);
	cout << p1;


}


void test02() {
	person p2;

	cout << (p2++)++;
	cout << p2;


}



int main(void) {

	test01();
	test02();
	//int s = 0;
	//cout << ++(++s) << endl;
	//cout << s << endl;
	system("pause");
	return 0;
}