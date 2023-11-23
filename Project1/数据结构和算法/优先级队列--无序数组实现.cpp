#include<iostream>
using namespace std;
//����������������ȼ����У�һ�˽�����һ�˳������ȼ��ߵ��ȳ���
typedef struct queue {
	int arr[6];
	int size;
}queue;

//��ʼ������
void init(queue* p) {
	p->size = 0;
}

//�ж϶����Ƿ��
bool pand1(queue* p) {
	if (p->size == 0) {
		return true;
	}
	return false;
}

//�ж϶����Ƿ���
bool pand2(queue* p,int maxspace) {
	if (p->size == maxspace) {
		return true;
	}
	return false;
}

//��ȡ���ȼ���ߵ�����ֵ
int  selectmax(queue* p,int maxspace) {
	int max = 0;
	for (int i = 1; i < maxspace; i++) {
		if (p->arr[i] >p->arr[max]) {
			max = i;
		}
	}
	return max;
}

//ɾ����Ӧ������Ԫ��
void remove1(queue* p,int k) {
	if (k < p->size - 1) {
		for (int i = k; i < p->size - 1; i++) {
			p->arr[i] = p->arr[i + 1];
		}
		p->size--;
	}
	p->size--;
}

//���
void offer(queue* p,int val) {
	if (pand2(p, 10)) {
		return;
	}
	p->arr[p->size++] = val;
}

//����
int peek(queue* p) {
	if (pand1(p)) {
		return -1;
	}
	int index = selectmax( p, p->size);
	int e= p->arr[index];
	remove1(p,index);
	return e;
}



int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	init(w);

	offer(w, 2);
	offer(w, 5);
	offer(w, 8);
	offer(w, 9);
	offer(w, 15);
	offer(w, 25);

	for (int j = 0; j < 6; j++) {
		cout << peek(w) << " ";
	}

	system("pause");
	return 0;
}