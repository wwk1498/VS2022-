#include<iostream>
#include<stack>
using namespace std;


int main() {

	//push(element)：将元素element压入栈顶。
	stack<int> myStack;
	myStack.push(10);


	//pop()：移除栈顶元素。
	stack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.pop();  // 栈顶元素20被移除


	//top()：返回栈顶元素的值，但不移除。
	stack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	int topElement = myStack.top();  // 获取栈顶元素的值


	//empty()：判断栈是否为空，返回布尔值。
	stack<int> myStack;
	if (myStack.empty()) {
		// 栈为空
	}
	else {
		// 栈非空
	}


	//size()：返回栈中元素的数量。
	stack<int> myStack;
	int count = myStack.size();  // 获取栈中元素的数量


	//swap(otherStack)：交换两个栈的内容。
	stack<int> myStack1;
	myStack1.push(10);
	stack<int> myStack2;
	myStack2.push(20);
	myStack1.swap(myStack2);  // 交换myStack1和myStack2的内容

	system("pause");
	return 0;
}