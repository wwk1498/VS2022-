#include<iostream>
using namespace std;
typedef struct node {
	int arry[10];
	int front;
	int rear;
}node;

// ��ʼ������
void initque(node*p) {
	p->front = 0;
	p->rear = 0;
}
bool pandauanque(node* p) {//�ж϶����Ƿ�Ϊ��
	if (p->front == p->rear) {
		return true;
	}
	return false;
}

bool pandauanquem(node* p) {//�ж϶����Ƿ�����
	if ((p->rear + 1) % 10 == p->front) {
		return true;
	}
	return false;
}

void enqueue(node* p,int index) {// ���
	if (pandauanquem(p)) {
		cout << "�������ˣ�" << endl;
		return;
	}
	p->arry[p->rear] = index;
	p->rear = (p->rear + 1) % 10;
}

int dequeue(node* p) {// ����
	if (pandauanque(p)) {
		cout << "���п��ˣ�" << endl;
		return -1;
	}
	int i = p->arry[p->front];
	p->front = (p->front + 1) % 10;
	return i;
}

// ��ն���
void clearQueue(node* p) {
	p->front = 0;
	p->rear = 0;
}


int main() {
	node* w = (node*)malloc(sizeof(node));
	initque(w);
	for (int i = 0; i < 20; i++) {
		enqueue(w, i+1);
	}
	for (int j = 0; j < 20; j++) {
		cout<<dequeue(w)<<" ";
	}
	system("pause");
	return 0;
}