#include<iostream>
using namespace std;

typedef struct node {
	struct node* left;//��һ���ڵ�ָ��
	int data;
	struct node* right;//��һ���ڵ�ָ��
}node;

typedef struct List {
	struct node* head;//ͷ�ڱ�
	struct node* tail;//β�ڱ�
}List;

//��ʼ��˫��������
List* initlist() {

	List* list =(List*)malloc(sizeof(List));
	list->head= (node*)malloc(sizeof(node));
	list->tail= (node*)malloc(sizeof(node));

	list->head->left = list->tail;
	list->head->right= list->tail;

	list->tail->left = list->head;
	list->tail->right = list->head;
	return list;
}

int main() {


	system("pause");
	return 0;
}