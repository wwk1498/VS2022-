#include<iostream>
using namespace std;
typedef struct node {
	int s[10];
	int i;
}node;
//��ʼ������
void initnod(node*p) {
	p->i = 0;
}
//�ж�ջ��
bool pand(node*p) {
	if (p->i == 0) {
		return true;
	}
	return false;
}
//�ж�ջ��
bool panduan(node*p) {
	if (p->i == 10) {
		return true;
	}
	return false;
}
//��ջ
void  push(node* p, int val) {
	if (panduan(p)) {
		cout << "ջ��" << endl;
		return;
	}
	p->s[p->i++] = val;
}

//��ջ
int pop(node* p) {
	if (pand(p)) {
		cout << "ջ��" << endl;
		return -1;
	}
	int index = p->s[p->i - 1];
	p->i--;
	return index;
}



int main() {
	node* a = (node*)malloc(sizeof(node));
	initnod(a);
	for (int i = 0; i < 13; i++) {
		push(a, i + 1);
	}
	for (int j = 0; j < 15; j++) {
		cout << pop(a) << " ";
	}
	system("pause");
	return 0;
}