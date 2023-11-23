#include<iostream>
using namespace std;
//��׼�ṹ��
typedef struct  DynamicArray {
	int* arry;//����
	int size;//Ԫ�ظ���,size<capacity
	int capacity;//����
}DynamicArray;

//��ʼ������ 
void init(DynamicArray*arryay,int capacity) {
	arryay->arry =(int* )malloc(sizeof(int)* capacity);
    if (arryay->arry == NULL) {
        cout << "�ڴ����ʧ�ܣ�" << endl;
        return;
    }
	arryay->size = 0;
	arryay->capacity = capacity;
}
//����Ԫ�ص�����
void add(DynamicArray* arryay,int value) {
	if (arryay->size == arryay->capacity) {
        arryay->capacity *= 2;
        arryay->arry = (int *)realloc(arryay->arry, sizeof(int) * arryay->capacity);
        if (arryay->arry == NULL) {
            cout << "�ڴ����ʧ�ܣ�" << endl;
            return;
        }
	}
	arryay->arry[(arryay->size)++] = value;
}
//ɾ��ָ��������Ԫ��
void delet(DynamicArray* arryay,int index) {
    if (index<0 || index>arryay->size - 1) {
        cout << "��������" << endl;
        return;
    }
    for (int i = index; i < arryay->size - 1; i++) {
        arryay->arry[i] = arryay->arry[i + 1];
    }
    arryay->size--;
}
//��ָ������������Ԫ�� 
void charu(DynamicArray* arryay, int index,int value) {
    if (index<0 || index>arryay->size - 1) {
        cout << "��������" << endl;
        return;
    }
    if(arryay->size == arryay->capacity){
        arryay->capacity *= 2;
        arryay->arry = (int*)realloc(arryay->arry, sizeof(int) * arryay->capacity);
        if (arryay->arry == NULL) {
            cout << "�ڴ����ʧ�ܣ�" << endl;
            return;
        }
    }

    for (int i = arryay->size; i >index; i--) {
        arryay->arry[i] = arryay->arry[i-1];
    }
    arryay->arry[index] = value;
    arryay->size++;
}


// ������̬���鲢�������Ԫ��
void traverse(DynamicArray *arryay) {
    for (int i = 0; i < arryay->size; i++) {
        cout << arryay->arry[i] << endl;
    }
}

//���ٶ�̬����
void xiaohui(DynamicArray* arryay) {
    free(arryay->arry);
    arryay->arry = NULL;
    arryay->capacity = 0;
    arryay->size = 0;
}

int main() {
    DynamicArray  arryay;
    init(&arryay, 4);//��ʼ������

    add(&arryay, 10);//����Ԫ�ص�����
    add(&arryay, 12);
    add(&arryay, 17);


    traverse(&arryay);// ������̬���鲢�������Ԫ��
    cout << "--------------------------" << endl;
    charu(&arryay,1,78);//����Ԫ��
    traverse(&arryay);// ������̬���鲢�������Ԫ��
    cout << "--------------------------" << endl;
    charu(&arryay, 1, 58);//����Ԫ��
    traverse(&arryay);// ������̬���鲢�������Ԫ��
    cout << "--------------------------" << endl;
    delet(&arryay,2);//ɾ��ָ������Ԫ��
    traverse(&arryay);// ������̬���鲢�������Ԫ��

    xiaohui(&arryay);//���ٶ�̬����
	system("pause");
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} DynamicArray;

// ��ʼ����̬����
void init(DynamicArray *arr, int capacity) {
    arr->array = (int *)malloc(sizeof(int) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
}

// ����Ԫ�ص���̬����
void add(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, sizeof(int) * arr->capacity);
    }
    arr->array[arr->size] = value;
    arr->size++;
}

// ɾ��ָ��λ�õ�Ԫ��
void removeAt(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }

    arr->size--;
}

// ������̬���鲢�������Ԫ��
void traverse(DynamicArray arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.array[i]);
    }
    printf("\n");
}

// ���ٶ�̬����
void destroy(DynamicArray *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray arr;
    init(&arr, 5);

    // ���Ԫ��
    add(&arr, 10);
    add(&arr, 20);
    add(&arr, 30);

    // ��ӡ��̬����
    printf("Array after adding elements: ");
    traverse(arr);

    // ɾ��ָ��λ��Ԫ��
    removeAt(&arr, 1);

    // ��ӡ��̬����
    printf("Array after removing element at index 1: ");
    traverse(arr);

    // ���ٶ�̬����
    destroy(&arr);

    return 0;
}*/