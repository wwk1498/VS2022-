#include<iostream>
using namespace std;

template<class T1, class T2>//����ʵ��-----1
class per;

//����ʵ��-----2
template<class T1, class T2>
void printper2(per<T1, T2> p) {
	cout << "����ʵ��" << endl;
	cout << p.m_id << endl;
	cout << p.m_name << endl;
}

template<class T1,class T2>
class per {

	//����ʵ��--1
	friend void printper(per<T1,T2> p) {
		cout << p.m_id << endl;
		cout << p.m_name << endl;
	}

	//����ʵ��-----3
	friend void printper2<>(per<T1, T2> p);
public:
	per(T1 id, T2 name) {
		this->m_id = id;
		this->m_name = name;
	}

private:
	T1 m_id;
	T2 m_name;
};

void test() {
	per<int, string>p1(1, "yyy");
	printper(p1);
}

void test01() {
	per<int, string>p1(1, "yyy");
	printper2(p1);
}

int main() {
	test01();

	system("pause");
	return 0;
}