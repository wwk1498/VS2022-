#include<iostream>
using namespace std;

class person {
public:
	person() {
		cout << "person���캯������" << endl;
	}
	virtual ~person() {
		cout << "person������������" << endl;
	}
	virtual void fun() = 0;
};

class son :public person {
public:
	string *n;
	son(string k) {
		cout << "son���캯������" << endl;
		n = new string(k);
	}
	~son() {
		if (n!=NULL) {
			cout << "son������������" << endl;
			delete n;
			n = NULL;
		}
	}
	void fun() {
		cout << *n+"��ˮ" << endl;
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