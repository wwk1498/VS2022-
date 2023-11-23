#include<iostream>
using namespace std;
//ջ��ֻ������һ����Ӻ��Ƴ����ݣ����ܲ�����һ��Ϊջ�ף���һ��Ϊջ����
//ֻ����һ��ɾ������ӣ�ջ����
typedef struct node {
	int data;
	struct node* next;
}node;
typedef struct List {
	struct node* head;
	struct node* tail;
}List;

//��ʼ��ջ
List* initlist() {
	List* list = (List*)malloc(sizeof(List));
	list->head = (node*)malloc(sizeof(node));
	list->tail = (node*)malloc(sizeof(node));
	list->head->next = list->tail;
	list->tail->next = list->head;
	return list;
}
//�ж�ջ��
bool pand1(List*p) {
	if (p->head->next == p->tail) {
		return true;
	}
	return false;
}
//��ջ
void push(List*p,int i) {
	node* tep = (node*)malloc(sizeof(node));
	tep->data = i;
	tep->next = p->head->next;
	p->head->next = tep;
}
//��ջ
int pop(List*p) {
	if (pand1(p)) {
		cout << "ջ���ˣ�" << endl;
		return -1;
	}
	node* temp = p->head->next;
	int index = temp->data;
	p->head->next = temp->next;
	free(temp);
	return index;
}

int main() {
	List* f = (List*)malloc(sizeof(List));
	f = initlist();
	for (int i = 0; i < 10; i++) {
		push(f, i + 1);
	}
	for (int j = 0; j < 15; j++) {
		cout << pop(f) << " ";
	}
	system("pause");
	return 0;
}