#include<iostream>
#include<stack>
using namespace std;


int main() {

	//push(element)����Ԫ��elementѹ��ջ����
	stack<int> myStack;
	myStack.push(10);


	//pop()���Ƴ�ջ��Ԫ�ء�
	stack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.pop();  // ջ��Ԫ��20���Ƴ�


	//top()������ջ��Ԫ�ص�ֵ�������Ƴ���
	stack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	int topElement = myStack.top();  // ��ȡջ��Ԫ�ص�ֵ


	//empty()���ж�ջ�Ƿ�Ϊ�գ����ز���ֵ��
	stack<int> myStack;
	if (myStack.empty()) {
		// ջΪ��
	}
	else {
		// ջ�ǿ�
	}


	//size()������ջ��Ԫ�ص�������
	stack<int> myStack;
	int count = myStack.size();  // ��ȡջ��Ԫ�ص�����


	//swap(otherStack)����������ջ�����ݡ�
	stack<int> myStack1;
	myStack1.push(10);
	stack<int> myStack2;
	myStack2.push(20);
	myStack1.swap(myStack2);  // ����myStack1��myStack2������

	system("pause");
	return 0;
}