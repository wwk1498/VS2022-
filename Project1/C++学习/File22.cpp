#include<iostream>
using namespace std;

class person {
public:
	virtual void drink() = 0;
	virtual void eat() = 0;
	virtual void make() = 0;
	void dosings() {
		drink();
		eat();
		make();
	}

};

class son :public person {
public:
	virtual void drink() {
		cout << "��ˮ" << endl;
	}
	virtual void eat() {
		cout << "�Է�" << endl;
	}
	virtual void make() {
		cout << "����" << endl;
	}

};

void  dosing(person*w) {
	w->dosings();
}


void  test01() {
	dosing(new son());
}
int main(void) {
	test01();
	system("pause");
	return 0;
}