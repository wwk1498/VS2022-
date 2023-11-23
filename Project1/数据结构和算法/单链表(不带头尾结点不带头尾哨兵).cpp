#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
}node;

//��������(����ͷ���)
node* createnode() {
    return NULL;
}
// ������ͷ������Ԫ��(ͷ�巨)
node* inserthead(node*head,int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = head;
    head=newnode;
    return head;
}

// ������β������Ԫ��(β�巨)
node* inserttail(node*head,int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return head;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// ��ȡ������
int getLinkedListLength(node* head) {
    int len = 0;
    node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}
//�޸�����Ԫ��Ϊ�µ�Ԫ��(���ݸ���Ԫ���޸�)
node* updatenode1(node*head,int value, int newvalue ) {
    if (head == NULL) {
        cout << "����Ϊ�գ�" << endl;
        //exit(-1);//��ֹ����
        return head;
    }
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            temp->data = newvalue;
            return head;
        }
        temp = temp->next;
    }
    cout << "�����޸�Ԫ�أ�" << endl;
    return head;
}
//�޸�����Ԫ��Ϊ�µ�Ԫ��(���ݸ��������޸�)
 node* updatenode2(node*head,int index,int newvalue ) {
     if (head == NULL) {
         cout << "����Ϊ�գ�" << endl;
         //exit(-1);//��ֹ����
         return head;
     }
     if (index > getLinkedListLength(head)||index<0) {
         cout << "�����λ������" << endl;
         //exit(-1);//��ֹ����
         return head;
     }
     int i = 1;
     node* temp = head;
     while (temp!=NULL) {
         if (i == index) {
             temp->data = newvalue;
             return head;
         }
         temp=temp->next;
         i++;
     }
}
// ������ָ��λ�ò���Ԫ��(��������)
node* insertAtPosition(node* head, int value, int index) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL) {
        cout << "���������Ϊ�գ�" << endl;
        //exit(-1);//��ֹ����
        return head;
    }
    if (index > getLinkedListLength(head) || index < 0) {
        cout << "�����λ������" << endl;
      //  exit(-1);//��ֹ����
        return head;
    }
    if (index == 1) {
        newnode->next = head;
        head = newnode;
        return head;
    }
    node* temp = head;
    int i = 1;
    while (i < index-1) {
        i++;
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
// ɾ������ָ��λ�õ�Ԫ��
node* deleteAtPosition(node* head, int index) {
    if (head == NULL) {
        cout << "���������Ϊ�գ�" << endl;
        //exit(-1);//��ֹ����
        return head;
    }
    if (index > getLinkedListLength(head)) {
        cout << "�����λ�ô��������ȣ�" << endl;
        //exit(-1);//��ֹ����
        return head;
    }
    int i = 1;
    node* pre = NULL;
    node* temp = head;
    if (index == 1) {
        head = temp->next;
        free(temp);
        temp = NULL;
        return head;
    }

    while (i < index) {
        pre = temp;
       temp= temp->next;
       i++;
    }
    pre->next = temp->next;
    free(temp);
    temp = NULL;
    return head;
}
// ����������ӡԪ��
void displayLinkedList(node* head) {
    if (head == NULL) {
        cout << "���������Ϊ�գ�" << endl;
       // exit(-1);//��ֹ����
        return ;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp=temp->next;
    }
}

// �ݹ����������ӡԪ��
void diguibl(node*head) {
    if (head == NULL) {
        return;
    }
    cout << head->data << "  " ;
    diguibl(head->next);
}


// ����Ԫ�����ڵ�λ��
int searchElement(node* head, int searchData) {
    if (head == NULL) {
        cout << "���������Ϊ�գ�" << endl;
        //exit(-1);//��ֹ����
        return 0;
    }
    int i = 1;
    node* temp = head;
    while (temp->data != searchData&&temp!=NULL) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        return i;
    }else {
        return -1;
    }
}
// ��ת����
node* reverseLinkedList(node* head) {
    if (head == NULL) {
        cout << "���������Ϊ�գ�" << endl;
        //exit(-1);//��ֹ����
        return head;
    }
    node* pre = NULL;
    node* temp = head;

    while (temp != NULL) {
        node*nep=temp->next;
        temp->next = pre;
        pre = temp;
        temp = nep;
    }
    head = pre;
    return head;
}

// �ϲ���������
node* mergeLinkedLists(node* head1, node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

//��������
void xiaohui(node**head) {
    node* p1= *head;
    node* p2 ;
    while (p1 != NULL) {
        p2 = p1;
        p1=p1->next;
        free(p2);
    }
    *head = NULL;
}
int main(void) {
    
    
    node* head=createnode();
    for (int i = 1; i <= 10; i++) {
        head = inserthead(head, i);
    }
    displayLinkedList(head);

    cout << endl;
    cout << "----------------------------" << endl;

    diguibl(head);

    cout << endl;
    cout << "----------------------------" << endl;

    node*head1= createnode();
    for (int i = 1; i <= 10; i++) {
        head1 = inserttail(head1, i);
    }
    displayLinkedList(head1);

    cout << endl;
    cout << "----------------------------" << endl;

    int len=getLinkedListLength(head1);
    cout << len << endl;

    cout << endl;
    cout << "----------------------------" << endl;

    head1 = updatenode1(head1, 86, 20);
    displayLinkedList(head1);

    cout << endl;
    cout << "----------------------------" << endl;

    head1 = updatenode2(head1, 13, 16);
    displayLinkedList(head1);

    cout << endl;
    cout << "----------------------------" << endl;

    head1 = insertAtPosition(head1, 56, 8);
    displayLinkedList(head1);

    cout << endl;
    cout << "----------------------------" << endl;

    head1 = deleteAtPosition(head1, 9);
    displayLinkedList(head1);

    cout << endl;
    cout << "----------------------------" << endl;

    int x = searchElement(head1, 56);
    cout << x << endl;

    cout << endl;
    cout << "----------------------------" << endl;

    head1 = reverseLinkedList(head1);
    displayLinkedList(head1);


    cout << endl;
    cout << "----------------------------" << endl;
    head1 = mergeLinkedLists(head, head1);
    displayLinkedList(head1);
    
	system("pause");
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;           // ����
    struct Node* next;  // ָ����һ���ڵ��ָ��
} Node;

// ��������
Node* createLinkedList() {
    return NULL;  // ���ؿ�ָ���ʾ����Ϊ��
}

// ������ͷ������Ԫ��
Node* insertAtHead(Node* head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;  // �����µ�ͷ�ڵ�
}

// ������β������Ԫ��
Node* insertAtTail(Node* head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

// ������ָ��λ�ò���Ԫ��
Node* insertAtPosition(Node* head, int newData, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        int i = 1;
        while (i < position - 1 && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Invalid position\n");
            return head;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// ɾ������ָ��λ�õ�Ԫ��
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Empty list\n");
        return head;
    }

    Node* temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
    } else {
        Node* prev = NULL;
        int i = 1;

        while (i < position && temp != NULL) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }

        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// ����������ӡԪ��
void displayLinkedList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
    } else {
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// ����Ԫ�����ڵ�λ��
int searchElement(Node* head, int searchData) {
    int position = 1;
    Node* current = head;
    while (current != NULL) {
        if (current->data == searchData) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;  // ����-1��ʾδ�ҵ�
}

// ��ȡ������
int getLinkedListLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// ��ת����
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

// �ϲ���������
Node* mergeLinkedLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head2;
    return head1;
}

// ��������Ļ�������
int main() {
    Node* head = createLinkedList();

    // ��ͷ��
    */