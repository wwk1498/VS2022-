#include<iostream>
using namespace std;

//����ģ��
template<typename T2>
T2 add(T2 a, T2 b) {
	return a + b;
}


//��ģ��
template<typename T1>
class fath {
public:
	T1 m;
	fath(T1 m) {
		this->m = m;
		cout << this->m << endl;
	}
};


//void test05() {
//	cout << add<int>(3, 6) << endl;
//	fath<int> s(2);
//
//}
int main() {
	cout << add<int>(3, 6) << endl;
	fath<int> s(2);
}













template<typename n1,typename n2>
class son {
public :
	n1 a;
	n2 name;
	son(n1 w,n2 m) {
		this->a = w;
		this->name = m;
	}

	void show() {
		cout << this->a << endl;
		cout << this->name<< endl;
	}
};

void test02() {
	son<int, string> p1(3, "rrr");
	p1.show();
}




class person {
public:
	int a;
	string name;
	person(int s, string n) {
		this->a = s;
		this->name = n;
	}
};

template <typename T>
bool muy(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//���廯���ȵ���
template <>bool muy(person& a, person& b) {
	if (a.a == b.a && a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}



void test01() {

	person p1(2, "ww");
	person p2(2, "ww");
	if (muy(p1,p2)) {
		cout << 111 << endl;
	}
	else {
		cout << 222 << endl;
	}

}

void mer(int a, int b) {//��ͨ����
	cout << a + b << endl;
}

template<typename T>//����ģ��
void mer(T a, T b) {
	cout << a + b << endl;
}

void test() {
	int a = 13;
	int b = 78;
	//mer(a, b);
	//mer<int>(a, b);
	//mer<>(a, b);//��ģ�������ǿ�Ƶ��ú���ģ��
}

int main() {
	test05();
	system("pause");
	return 0;
}