#include<iostream>
using namespace std;
/*
* ��C++�У����಻��ֱ��ʹ��new�ؼ����������������
���ǿ���ͨ������ָ��ָ���������Ȼ��ʹ���麯����ʵ�ֶ�̬��
* class Parent {
  public:
    virtual void doSomething() {
        // ����Ĳ���
    }
};

class Child : public Parent {
  public:
    void doSomething() {
        // ����Ĳ���
    }
};

int main() {
    Parent* obj = new Child();  // ͨ������ָ��ָ���������

    obj->doSomething();  // �������������麯��

    delete obj;

    return 0;
}
*/




//��̬������
class person {
public:
	int a;
	int b;
	virtual int add() {
		return 0;
	}
};
class ma :public person {
public:
	int add() {
		return a+b;
	}
};

void  test01() {
	person  *ab=new ma() ;
	ab->a = 12;
	ab->b= 13;
	cout << ab->add() << endl;

}
int main(void) {
	test01();
	system("pause");
	return 0;
}

