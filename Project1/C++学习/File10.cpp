#include<iostream>
using namespace std;

class person {

public:
	int *m_a;

	person(int a) {
		m_a = new int(a);
	}

	~person() {
		if (m_a != NULL) {
			delete m_a;
			m_a = NULL;
		}
	}

	person& operator=(person &p) {
		if (m_a != NULL) {
			delete m_a;
			m_a = NULL;
		}
		m_a =new int(*p.m_a);
		return *this;
	}
};

void test01() {
	person p1(12);
	person p2(34);
	person p3(3);
	p3=p2 = p1;
	cout << *p1.m_a << endl;
	cout << *p2.m_a << endl;
	cout << *p3.m_a << endl;
}
int main(void) {
	test01();
	system("pause");

	return 0;
}

