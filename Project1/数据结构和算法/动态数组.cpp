#include<iostream>
using namespace std;
//标准结构体
typedef struct  DynamicArray {
	int* arry;//数组
	int size;//元素个数,size<capacity
	int capacity;//容量
}DynamicArray;

//初始化数组 
void init(DynamicArray*arryay,int capacity) {
	arryay->arry =(int* )malloc(sizeof(int)* capacity);
    if (arryay->arry == NULL) {
        cout << "内存分配失败！" << endl;
        return;
    }
	arryay->size = 0;
	arryay->capacity = capacity;
}
//增加元素到数组
void add(DynamicArray* arryay,int value) {
	if (arryay->size == arryay->capacity) {
        arryay->capacity *= 2;
        arryay->arry = (int *)realloc(arryay->arry, sizeof(int) * arryay->capacity);
        if (arryay->arry == NULL) {
            cout << "内存分配失败！" << endl;
            return;
        }
	}
	arryay->arry[(arryay->size)++] = value;
}
//删除指定索引的元素
void delet(DynamicArray* arryay,int index) {
    if (index<0 || index>arryay->size - 1) {
        cout << "索引错误！" << endl;
        return;
    }
    for (int i = index; i < arryay->size - 1; i++) {
        arryay->arry[i] = arryay->arry[i + 1];
    }
    arryay->size--;
}
//向指定索引插入新元素 
void charu(DynamicArray* arryay, int index,int value) {
    if (index<0 || index>arryay->size - 1) {
        cout << "索引错误！" << endl;
        return;
    }
    if(arryay->size == arryay->capacity){
        arryay->capacity *= 2;
        arryay->arry = (int*)realloc(arryay->arry, sizeof(int) * arryay->capacity);
        if (arryay->arry == NULL) {
            cout << "内存分配失败！" << endl;
            return;
        }
    }

    for (int i = arryay->size; i >index; i--) {
        arryay->arry[i] = arryay->arry[i-1];
    }
    arryay->arry[index] = value;
    arryay->size++;
}


// 遍历动态数组并输出所有元素
void traverse(DynamicArray *arryay) {
    for (int i = 0; i < arryay->size; i++) {
        cout << arryay->arry[i] << endl;
    }
}

//销毁动态数组
void xiaohui(DynamicArray* arryay) {
    free(arryay->arry);
    arryay->arry = NULL;
    arryay->capacity = 0;
    arryay->size = 0;
}

int main() {
    DynamicArray  arryay;
    init(&arryay, 4);//初始化数组

    add(&arryay, 10);//增加元素到数组
    add(&arryay, 12);
    add(&arryay, 17);


    traverse(&arryay);// 遍历动态数组并输出所有元素
    cout << "--------------------------" << endl;
    charu(&arryay,1,78);//插入元素
    traverse(&arryay);// 遍历动态数组并输出所有元素
    cout << "--------------------------" << endl;
    charu(&arryay, 1, 58);//插入元素
    traverse(&arryay);// 遍历动态数组并输出所有元素
    cout << "--------------------------" << endl;
    delet(&arryay,2);//删除指定索引元素
    traverse(&arryay);// 遍历动态数组并输出所有元素

    xiaohui(&arryay);//销毁动态数组
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

// 初始化动态数组
void init(DynamicArray *arr, int capacity) {
    arr->array = (int *)malloc(sizeof(int) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
}

// 增加元素到动态数组
void add(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, sizeof(int) * arr->capacity);
    }
    arr->array[arr->size] = value;
    arr->size++;
}

// 删除指定位置的元素
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

// 遍历动态数组并输出所有元素
void traverse(DynamicArray arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.array[i]);
    }
    printf("\n");
}

// 销毁动态数组
void destroy(DynamicArray *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray arr;
    init(&arr, 5);

    // 添加元素
    add(&arr, 10);
    add(&arr, 20);
    add(&arr, 30);

    // 打印动态数组
    printf("Array after adding elements: ");
    traverse(arr);

    // 删除指定位置元素
    removeAt(&arr, 1);

    // 打印动态数组
    printf("Array after removing element at index 1: ");
    traverse(arr);

    // 销毁动态数组
    destroy(&arr);

    return 0;
}*/