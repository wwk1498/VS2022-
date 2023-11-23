#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;

//��ʼ������(����ͷβ���)
/*node* initnode() {
	node* head = (node*)malloc(sizeof(node));
	node* tail = (node*)malloc(sizeof(node));
	tail->next = NULL;
	head->next = tail;
	return head;
}*/

// ������ͷ������Ԫ��(ͷ�巨)
void inserthead(node* head, node*tail, int value) {
	node*newnode= (node*)malloc(sizeof(node));
	newnode->data = value;

	node* tep = head;
	if (tep->next != tail) {
		newnode->next = tep->next;
		tep->next = newnode;
	}
	else {
		newnode->next = tail;
		tep->next = newnode;
	}
}
// ����������ӡԪ��
void displayLinkedList(node* head,node*tail) {
	node* tep = head;
	while (tep->next != tail) {
		tep = tep->next;
		cout << tep->data <<"   " ;
	}
	return;
}
//��������
void xiaohui(node**head,node**tail) {
	node* tep = *head;
	while (tep->next != *tail) {
		node* pre = tep;
		tep = tep->next;
		free(pre);
	}
	free(tep);
	free(*tail);
	*head = NULL;
	*tail = NULL;
}

int main() {
	//��ʼ��ͷβ���
	node* head = (node*)malloc(sizeof(node));
	node* tail = (node*)malloc(sizeof(node));
	tail->next = NULL;
	head->next = tail;


	//for (int i = 1; i <= 10; i++) {
		 //inserthead(head, tail, i);
	//}

	inserthead(head, tail, 12);
	inserthead(head, tail, 142);

	displayLinkedList(head,tail);
	xiaohui(&head, &tail);

	if (head == NULL && tail == NULL) {
		cout << "1111" << endl;
	}
	else {
		cout << "2222" << endl;
	}
	system("pause");
	return 0;
}