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

	person& operator++() {//ǰ�õ���������Ϊperson�Ƿ����丱�������Ǳ��壬����Ϊperson&���Ƿ��ر���ı��������ԶԱ�������޸�
		a++;
		return *this;
	}

	person operator++(int) {//���õ���
		person temp = *this;//�ֲ����������������꣬�Զ�����
		a++;
		return temp;//����
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