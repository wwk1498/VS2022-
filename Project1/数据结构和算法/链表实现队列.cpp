#include<iostream>
using namespace std;
//���� :�Ƚ��ȳ�
typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct List {
	struct node* head;//ͷ�ڱ�
	struct node* tail;//β�ڱ�
	int size;//������
	int capacity;//����
}List;

List* initlist() {//������ͷβ�ڱ��Ķ���
	List* list = (List*)malloc(sizeof(List));
	list->head = (node*)malloc(sizeof(node));
	list->tail = (node*)malloc(sizeof(node));
	list->size = 0;
	list->capacity = 5;
	list->head->next = list->tail;
	list->tail->next = list->head;
	return list;
}


bool  pandaun(List* p) {//�ж϶����Ƿ�Ϊ��
	if (p->head->next == p->tail) {
		return true;
	}
	else {
		return false;
	}
}

bool panduanlit(List* p) {//�ж϶����Ƿ���
	if (p->size == p->capacity) {
		return true;
	}
	else {
		return false;
	}
}

List* addlist(List* p, int i) {//��������Ԫ��
	if (panduanlit(p)) {
		cout << "�������ˣ�" << endl;
		return p;
	}
	node* tep = (node*)malloc(sizeof(node));
	tep->data = i;
	tep->next = p->head->next;
	p->head->next = tep;
	p->size++;
	return  p;
}

int printlist(List* p) {//��ȡ����Ԫ��ֵ,���ڶ�����ɾ����ֵ
	if (pandaun(p)) {
		return NULL;
	}
	node* left = p->head;
	node* tep= p->head->next;
	while (tep->next != p->tail) {
		left = tep;
		tep = tep->next;
	}
	int index = tep->data;
	left->next = p->tail;
	free(tep);
	tep = NULL;
	return index;
}
void prinlit(List* p) {//ѭ����������е�ֵ

	while(p->head->next != p->tail) {
		cout << printlist(p) << " ";
	}
}


int main() {
	List* Q = initlist();
	Q = addlist(Q, 8);
	Q = addlist(Q, 5);
	Q = addlist(Q, 9);
	Q = addlist(Q, 2);
	Q = addlist(Q, 8);
	Q = addlist(Q, 67);
	prinlit(Q);


	system("pause");
	return 0;
}