#include<iostream>
using namespace std;
typedef struct node {
	int arry[10];
	int i;
	int j;
}node;
//�����ص㣺һ��ɾ����ͷ������һ����ӣ�β��
//
//��ģ���㣺(������������2��n�η����ж�ĳ��m��2��n�η�����m&(m-1)=0;��m��2��n�η�
//i%j=k;
// ���j��2��n�η�
//��i�ĺ�nλ��Ϊ����(ģ��
//��i�ĺ�nλ�ķ�������2^n-1��λ��
//����N/m=p.......q;ͬʱm��2��n�η������̣�p=N>>n,   ������q=N&(2^n-1)
//�ô������ܸ��ߣ����ÿ��Ƿ���λ��Ӱ��



//��ʼ������
void initnode(node*p) {
	p->i = 0;
	p->j = 0;
}
bool pandauanque(node* p) {//�ж϶����Ƿ�Ϊ��
	if (p->i == 10) {
		return true;
	}
	return false;
}
bool pandauanquem(node* p) {//�ж϶����Ƿ�����
	if (p->j==10) {
		return true;
	}
	return false;
}
void enqueue(node* p, int index) {// ���
	if (pandauanquem(p)) {
		cout << "�������ˣ�" << endl;
		return;
	}
	p->arry[p->j % 10] = index;
	p->j++;
}
int dequeue(node* p) {// ����
	if (pandauanque(p)) {
		cout << "���п��ˣ�" << endl;
		return -1;
	}
	int i = p->arry[p->i%10];
	p->i++;
	return i;
}


int main() {
	/*node* w = (node*)malloc(sizeof(node));
	initnode(w);
	for (int i = 0; i < 20; i++) {
		enqueue(w, i + 1);
	}
	for (int j = 0; j < 20; j++) {
		cout << dequeue(w) << " ";
	}*/
	int num = 7;
	num = num >> 1;//��
	int p = num & 1;//����
	cout << p<< endl;
	system("pause");
	return 0;
}