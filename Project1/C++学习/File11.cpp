#include<iostream>
using namespace std;

class person {

public:
	int m_a;
	string m_name;

	person(int a,string name) {
		m_a = a;
		m_name = name;
	}

	bool operator==(person &p) {
		if (m_a == p.m_a && m_name == p.m_name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(person& p) {
		if (m_a == p.m_a && m_name == p.m_name) {
			return false;
		}
		else {
			return true;
		}
	}

};

void test01() {
	person p1(15, "Tom");
	person p2(15, "Tom");
	if (p1 == p2) {
		cout << "111" << endl;
	}
	else {
		cout << "222" << endl;
	}
}
int main(void) {
	test01();
	system("pause");

	return 0;
}
