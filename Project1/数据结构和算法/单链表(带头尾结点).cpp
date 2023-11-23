#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;

//初始化链表(创建头尾结点)
/*node* initnode() {
	node* head = (node*)malloc(sizeof(node));
	node* tail = (node*)malloc(sizeof(node));
	tail->next = NULL;
	head->next = tail;
	return head;
}*/

// 在链表头部插入元素(头插法)
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
// 遍历链表并打印元素
void displayLinkedList(node* head,node*tail) {
	node* tep = head;
	while (tep->next != tail) {
		tep = tep->next;
		cout << tep->data <<"   " ;
	}
	return;
}
//销毁链表
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
	//初始化头尾结点
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