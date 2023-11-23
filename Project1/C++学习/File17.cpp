#include<iostream>
using namespace std;

class person {
public:
	static int a;
	static void fun() {
		cout << "111" << endl;
	}
};

int person::a = 100;

class mam :public person {
public:
	static int a;
	static void fun() {
		cout << "222" << endl;
	}
};

int mam::a = 200;


void  test01() {

	mam p;
	cout << p.a <<endl;
	cout << p.person::a << endl;

	cout << mam::a << endl;
	cout << person::a << endl;
	cout << mam::person::a << endl;

	mam::fun();
	person::fun(); 
	mam::person::fun(); 
}


int main(void) {
	test01();
	system("pause");
	return 0;
}