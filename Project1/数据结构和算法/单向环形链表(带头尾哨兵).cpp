#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct List {
	struct node* head;//ͷ�ڱ�
	struct node* tail;//β�ڱ�
}List;

//��ʼ������������
List* initlist() {

	List *list=(List*)malloc(sizeof(List));
	list->head= (node*)malloc(sizeof(node));
	list->tail= (node*)malloc(sizeof(node));

	list->head->next = list -> tail;
	list->tail->next = list->head;

	return list;
}


int main(void) {
	
	system("pause");
	return 0;
}