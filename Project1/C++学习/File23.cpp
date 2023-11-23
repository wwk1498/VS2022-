#include<iostream>
using namespace std;

class person {
public:
	person() {
		cout << "person构造函数调用" << endl;
	}
	virtual ~person() {
		cout << "person析构函数调用" << endl;
	}
	virtual void fun() = 0;
};

class son :public person {
public:
	string *n;
	son(string k) {
		cout << "son构造函数调用" << endl;
		n = new string(k);
	}
	~son() {
		if (n!=NULL) {
			cout << "son析构函数调用" << endl;
			delete n;
			n = NULL;
		}
	}
	void fun() {
		cout << *n+"喝水" << endl;
	}
};


void  test01() {
	person* p=new son("Tom");
	p->fun();
	delete p;
}
int main(void) {
	test01();
	system("pause");
	return 0;
}