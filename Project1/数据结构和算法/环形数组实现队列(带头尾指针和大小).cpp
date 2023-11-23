#include<iostream>
using namespace std;
typedef struct node {
	int arry[10];
	int front;
	int rear;
	int size;//Ԫ�ظ���
}node;

// ��ʼ������
void initque(node* p) {
	p->front = 0;
	p->rear = 0;
	p->size = 0;
}
bool pandauanque(node* p) {//�ж϶����Ƿ�Ϊ��
	if (p->size==0) {
		return true;
	}
	return false;
}

bool pandauanquem(node* p,int max) {//�ж϶����Ƿ�����
	if (p->size==max) {
		return true;
	}
	return false;
}

void enqueue(node* p, int index,int max) {// ���
	if (pandauanquem(p,max)) {
		cout << "�������ˣ�" << endl;
		return;
	}
	p->arry[p->rear] = index;
	p->rear = (p->rear + 1) % 10;
	p->size++;
}

int dequeue(node* p) {// ����
	if (pandauanque(p)) {
		cout << "���п��ˣ�" << endl;
		return -1;
	}
	int i = p->arry[p->front];
	p->front = (p->front + 1) % 10;
	p->size--;
	return i;
}

// ��ն���
void clearQueue(node* p) {
	p->front = 0;
	p->rear = 0;
	p->size = 0;
}


int main() {
	node* w = (node*)malloc(sizeof(node));
	initque(w);
	for (int i = 0; i < 15; i++) {
		enqueue(w, i + 1,10);
	}
	for (int j = 0; j <15; j++) {
		int m = dequeue(w);
		if (m != -1) {
			cout << m<< " ";
		}
	}
	system("pause");
	return 0;
}