
/*
堆排序：
    1.建立大顶堆
	2.每次将堆顶元素（最大值）交换到末尾，调整堆结构以符合大顶堆特性

*/

#include<iostream>
using namespace std;



//返回两个子节点最大值的下标
int retup(int p[], int a, int b,int size) {
    if (a >=size || b >= size|| p[a] >= p[b]) {
        return a;
    }
    return b;
}

//交换两个元素
void swap(int p[], int i, int j) {
    int tep = p[i];
    p[i] = p[j];
    p[j] = tep;
}

//下潜
void down(int p[], int i,int size) {
    int max = retup(p, 2 * i + 1, 2 * i + 2,size);
    while (p[i] < p[max] && max <size) {
        swap(p, i, max);
        i = max;
        max = retup(p, 2 * i + 1, 2 * i + 2,size);
    }
}

//建堆
void initqueue(int p[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        down(p, i,size);
    }
}

//堆排序过程
void heapflf(int p[],int size) {
    
    initqueue(p, size);//建堆
    for (int right = size - 1; right > 0; right--) {
        swap(p, 0, right);
        down(p, 0,right);
    }
}




int main() {
    int d[8] = { 34,19,2,80,345,56,39,29 };
    heapflf(d, 8);

    for (int e : d) {
        cout << e << " ";
    }
	system("pause");
	return 0;
}