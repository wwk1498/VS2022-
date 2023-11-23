/*
queue �� deque ��C++�ж�������������������һЩ�������֮ͬ����

��֮ͬ����

����C++��׼���ṩ��������
��֧����β�����Ԫ�غ���ͷ��ɾ��Ԫ�صĲ�����
���ṩ�����ڲ�ѯ������С�ķ������� size()��
��֧�ֵ�������ʹ�á�

����

�ײ�ʵ�ֲ�ͬ��queue ���� deque �� list ʵ�֣��� deque �ǻ��ڷֶ������ʵ�֡�
���ܲ�ͬ��queue �Ƕ��У�ֻ���ڶ�β���Ԫ�أ��ڶ�ͷɾ��Ԫ��,���ܽ����������Ԫ�أ�deque ��˫�˶��У���������β���˽��в���ɾ�����������������м�����ɾ��Ԫ�ء�
�ӿڲ�ͬ��queue �ṩ�� push()��pop()��front()��back()��empty() �� size() �Ȳ������ڶ��еĻ���������deque ���ṩ�˸��ḻ�Ľӿڣ����˶��еĻ��������⣬�������� vector һ��ʹ�õ�������������ʺͶ�̬����������С��
������ʧЧ����ʹ�� deque ����Ԫ�ز����ɾ������ʱ����������β���еĲ����⣬�����ɾ��Ԫ�ؿ������������ʧЧ���� queue ֻ�ܴ�һ�˲����ɾ��Ԫ�أ��������������ʧЧ��
��������ѡ����ʵ����������ֻ��Ҫʵ�ֶ��еĹ��ܣ�����ʹ�� queue�������Ҫ����β���˽��в����ɾ���������Լ��������Ԫ�أ�����ʹ�� deque��
*/


#include<iostream>
#include<queue>
using namespace std;

class Vertex {
public:
	int disk;
	Vertex(int _disk):disk(_disk){}
};


class CompareVertex {
public:
	bool operator()(const Vertex* v1, const Vertex* v2) const {
		return v1->disk < v2->disk;
	}
};



int main() {
	
	//1.���ȶ���
	
	//����Ĭ�������(Ԫ�شӴ�С)�����ȶ���
	priority_queue<int> my;//�������ȶ���
	my.push(12);
	my.push(3);
	my.push(67);
	while (!my.empty()) {
		cout << my.top() << " ";
		my.pop();
	}
	//���67 12 3


	//����(Ԫ�ش�С����)�����ȶ���
	priority_queue<int,vector<int>,greater<int>> my;//�������ȶ���,
	my.push(12);
	my.push(3);
	my.push(67);
	while (!my.empty()) {
		cout << my.top() << " ";
		my.pop();
	}
	//��� 3 12 67


	/*
	
	priority_queue������һ����׼���е����ȶ�������ģ���ࡣ
	<Vertex*, vector<Vertex*>, CompareVertex>������ģ���� priority_queue ��ģ���������ָ�������ȶ�����Ԫ�ص����͡��ײ����������ͺͱȽ��������͡�
	Vertex* ���������ȶ�����Ԫ�ص����͡������ָ������ Vertex* �������ڵ�����ͣ���ָ�� Vertex ���͵�ָ�롣
	vector<Vertex*>���������ȶ��еĵײ��������͡�����ѡ���� vector ��Ϊ�ײ��������洢Ԫ�ء�
	CompareVertex�����ǱȽ��������͡�����ʹ��ǰ�涨��� CompareVertex �ṹ����Ϊ�ڵ�Ƚ�����

	*/

	priority_queue<Vertex*, vector<Vertex*>, CompareVertex> pq;

	pq.push(new Vertex(5));
	pq.push(new Vertex(1));
	pq.push(new Vertex(10));
	pq.push(new Vertex(3));

	while (!pq.empty()) {
		cout << pq.top()->disk << " ";
		pq.pop();
	}
	//��� 1 3 5 10









//----------------------------------------------------------------
    //��������
	
	//push() : ��queueβ�����һ��Ԫ�ء�
	queue<int> q;
	q.push(10);
	q.push(20);


	//pop() : �Ƴ�queueͷ����һ��Ԫ�ء�
	queue<int> q;
	q.push(10);
	q.push(20);
	q.pop();


	//front() : ����queue�ĵ�һ��Ԫ�أ�������ɾ������
	queue<int> q;
	q.push(10);
	q.push(20);
	int frontElement = q.front();


	//back() : ����queue�����һ��Ԫ�أ�������ɾ��������queue�����У�back()�������ص�Ԫ�ؾ��������ӵ�Ԫ�أ������Ǻ�std::dequeһ�������һ��Ԫ�ء�
	queue<int> q;
	q.push(10);
	q.push(20);
	int backElement = q.back();


	//empty() : ���queue�Ƿ�Ϊ�գ����ز���ֵ��
	queue<int> q;
	bool isEmpty = q.empty();


	//size() : ���ص�ǰqueue�е�Ԫ��������
	queue<int> q;
	q.push(10);
	q.push(20);
	int size = q.size();

	system("pause");
	return 0;
}