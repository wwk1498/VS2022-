#include<iostream>
using namespace std;
#include"MyArry.hpp"

class person {
public:
	string m_name;
	int m_id;
	person() {};
	person(string name,int id) {
		this->m_id = id;
		this->m_name = name;
	}
};

void printq1(MyArray<person>& t) {
	for (int i = 0; i < t.get_Size(); i++) {
		cout << t[i].m_id << "   " << t[i].m_name << endl;
	}
}


void test02() {
	MyArray<person>q1(10);
	person x1("wert", 1);
	person x2("wertr", 2);
	person x3("werty", 3);
	person x4("werto", 4);

	q1.push_back(x1);
	q1.push_back(x2);
	q1.push_back(x3);
	q1.push_back(x4);

	printq1(q1);
	cout << "数组容量：" << q1.get_Capacity() << endl;
	cout << "数组大小：" << q1.get_Size() << endl;
}




void printarry(MyArray<int> &y) {
	for (int i = 0; i < y.get_Size(); i++) {
		cout << y[i] << endl;
	}
}

void test() {
	MyArray<int>p1(10);
	for (int i = 0; i < 10; i++) {
		p1.push_back(i);
	}
	printarry(p1);
	cout << "数组容量：" <<p1.get_Capacity() <<endl;
	cout << "数组大小：" << p1.get_Size()<<endl;

	MyArray<int>p2(p1);
	p2.pop_back();
	printarry(p2);
	cout << "数组容量：" << p2.get_Capacity() << endl;
	cout << "数组大小：" << p2.get_Size() << endl;
}
int main() {
	test02();

	system("pause");
	return 0;
}