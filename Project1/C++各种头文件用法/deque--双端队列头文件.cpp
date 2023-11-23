/*
deque:˫�˶��С�
deque��һ����̬���飬���������˽��и�Ч�Ĳ����ɾ��������
��vector��ȣ�deque����β���˶����Խ��в����ɾ��������
��vectorֻ����β�����С�


ʹ��deque��������Ҫ������Ƶ�������ɾ��Ԫ�ص�������ṩ�ϸߵ����ܡ�
��Ҫע����ǣ���vector��ȣ�����deque���ڲ�ʵ�ָ�Ϊ���ӣ����ܻᵼ����΢��һЩ�ķ����ٶȡ�

*/

#include<iostream>
#include<deque>
using namespace std;


int main() {

	//push_back() : ��dequeβ�����һ��Ԫ�ء�
	deque<int> dq;
	dq.push_back(10); // {10}
	dq.push_back(20); // {10, 20}


	//push_front() : ��dequeͷ�����һ��Ԫ�ء�
	deque<int> dq;
	dq.push_front(10); // {10}
	dq.push_front(20); // {20, 10}


	//pop_back() : �Ƴ�dequeβ����һ��Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	dq.pop_back(); // {10, 20}


	//pop_front() : �Ƴ�dequeͷ����һ��Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	dq.pop_front(); // {20, 30}


	//size() : ���ص�ǰdeque�е�Ԫ��������
	deque<int> dq = { 10, 20, 30 };
	int size = dq.size(); // 3


	//empty() : ���deque�Ƿ�Ϊ�գ����ز���ֵ��
	deque<int> dq = { 10, 20, 30 };
	bool isEmpty = dq.empty(); // false


	//clear() : ���deque�е�����Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	dq.clear(); // {}


	//resize() : ����deque�Ĵ�С���������ӻ����Ԫ��������
	deque<int> dq = { 10, 20, 30 };
	dq.resize(5); // {10, 20, 30, 0, 0}
	dq.resize(2); // {10, 20}


	//at() : ����ָ��λ�õ�Ԫ�أ����б߽��顣
	deque<int> dq = { 10, 20, 30 };
	int element = dq.at(1); // 20


	//front() : ����deque�ĵ�һ��Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	int firstElement = dq.front(); // 10


	//back() : ����deque�����һ��Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	int lastElement = dq.back(); // 30


	//erase() : �Ƴ�ָ��λ�û�ָ����Χ��Ԫ�ء�
	deque<int> dq = { 10, 20, 30, 40, 50 };
	dq.erase(dq.begin() + 2); // {10, 20, 40, 50}
	dq.erase(dq.begin() + 1, dq.begin() + 3); // {10, 50}


	//insert() : ��ָ��λ�ò���һ������Ԫ�ء�
	deque<int> dq = { 10, 20, 30 };
	dq.insert(dq.begin() + 1, 15); // {10, 15, 20, 30}
	dq.insert(dq.begin() + 2, 2, 25); // {10, 15, 25, 25, 20, 30}


	//��ת�����ڵ�Ԫ��
	deque<int> dq = { 1, 2, 3, 4, 5 };
	reverse(dq.begin(), dq.end());
	for (const auto& element : dq) {
		std::cout << element << " ";
	}//5,4,3,2,1



	system("pause");
	return 0;
}