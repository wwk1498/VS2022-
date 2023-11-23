#include<iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;


// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//创建带头结点的链表
void create(Node** head) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->next = NULL;
}


int main() {
    Node* head = NULL;
    create(&head);
    Node*p1= (Node*)malloc(sizeof(Node));
    p1->data = 1;
    p1->next = NULL;
    head->next = p1;

    Node* tep = head;
    while (tep->next != NULL) {
        tep=tep->next;
        cout << tep->data << endl;
    }
    system("pause");
    return 0;
}