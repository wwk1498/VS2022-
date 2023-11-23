#include<iostream>
using namespace std;
//����1��������ռ�Ϊn,��ֻ�ܴ洢n-1��Ԫ�أ�
//�Ż������洢���Ƿ�����Ԫ�أ�����ȡ��Ԫ�غ�������Ϊnull���ͷ��ڴ�
typedef struct queue {
	int  arry[10];
	int i;
	int j;
}queue;

//��ʼ������
void initque(queue*p) {
	p->i = 0;
	p->j = 0;
}
//�ж϶����Ƿ��
bool pand1(queue* p) {
	if (p->i == p->j) {
		return true;
	}
	return false;
}

//��������j
int pullj(int j, int maxspace) {
	if (j>= maxspace) {
		return 0;
	}
	return j + 1;
}

//��������i
int pulli(int i, int maxspace) {
	if (i <= 0) {
		return maxspace - 1;
	}
	return i - 1;
}

//�ж϶����Ƿ���
bool pand(int i, int j,int maxspace) {
	if (i < j) {
		return j - i == maxspace - 1;
	}
	else if (j < i) {
		return i - j == 1;
	}
	else {
		return false;
	}
}
//�ڶ���ͷ������Ԫ��
void offerfirst(queue*p,int space,int val) {
	if (pand(p->i, p->j, space)) {
		cout << "����" << endl;
		return;
	}
	p->i= pulli(p->i, space);
	p->arry[p->i] = val;
}
//�ڶ���β������Ԫ��
void offerlist(queue* p, int space, int val) {
	if (pand(p->i, p->j, space)) {
		cout << "����" << endl;
		return;
	}
	p->arry[p->j] = val;
	p->j= pullj(p->j, space);
}
//�ڶ���ͷ��ȡ��Ԫ��
int pollfirst(queue* p, int space) {
	if (pand1(p)) {
		cout << "����" << endl;
		return -1;
	}
	int e = p->arry[p->i];
	p->i = pullj(p->i, space);
	return e;
}
//�ڶ���β��ȡ��Ԫ��
int polllist(queue* p, int space) {
	if (pand1(p)) {
		cout << "����" << endl;
		return -1;
	}
	p->j = pulli(p->j, space);
	return p->arry[p->j];
}
int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	initque(w);
	for (int i = 0; i < 9; i++) {//ע��ѭ������Ҫ��ʵ��������һ�Ų������
		offerfirst(w, 9, i+1);
	}

	for (int j = 0; j < 9; j++) {
		int em = pollfirst(w, 9);//���������Щ����
		if (em != -1) {
			cout << em << " ";
		}
	}
	
	system("pause");
	return 0;
}