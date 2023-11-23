#include<iostream>
using namespace std;

class person {
public:
	person() {
		cout << "person 1111" << endl;
	}
	~person() {
		cout << "~person 1111" << endl;
	}
};


class man :public person {
public:
	man() {
		cout << "man 1111" << endl;
	}
	~man() {
		cout << "~man 1111" << endl;
	}
};

void  test01() {
	//person p1;
	man m;

}
int main(void) {
	test01();
	system("pause");
	return 0;
}