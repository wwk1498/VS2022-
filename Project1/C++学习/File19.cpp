#include<iostream>
using namespace std;

//��̬��̬����������
//1.�м̳й�ϵ
//2.������д�����麯��

//��̬��̬ʹ�ã�
//�����ָ���������ִ���������

class animal {
public:
	virtual void speak() {
		cout << "dw��˵��" << endl;
	}
};

class cat :public animal {
public:
	 void speak() override{
		cout << "m��˵��" << endl;
	}
};
class dog :public animal {
public:
	void speak() override {
		cout << "g��˵��" << endl;
	}
};

void  dospeak(animal & anim) {
	anim.speak();
}
void  test01() {
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}
int main(void) {
	test01();
	system("pause");
	return 0;
}