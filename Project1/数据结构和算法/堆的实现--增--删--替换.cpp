//堆：基于树的数据结构，通常用完全二叉树实现，堆的特征：
//1.大堆顶中，任意节点C与他的父节点P符合 P.value>=C.value
//2.小堆顶中，任意节点C与他的父节点P符合 P.value<=C.value
//3.最顶层节点没有父亲，称为root根节点

//若从0开始用一维数组存储节点数据：当i>0时，节点i的父节点索引为floor((i-1)/2),节点i的左子节点索引为2i+1,右子节点索引为2i+2，前提是他们都<size
//若从1开始用一维数组存储节点数据：当i>1时，节点i的父节点索引为floor(i/2),节点i的左子节点索引为2i,右子节点索引为2i+1，前提是他们都<size

/*
* 入堆新元素：加到数组末尾（索引位置child),不断比较新元素与它父亲（parent)的优先级：
*     1.如果父节点优先级低，则向下移动，找下一个父节点parent
*     2.直至父节点优先级更高或者child==0为止
*/

/*
* 元素出堆：交换堆顶和尾部的元素，让尾部元素出堆
* （下潜)
*    1.从堆顶元素开始，将父元素与两个孩子较大者交换
*    2.直到父元素大于两个孩子，或者没有孩子为止
*
*/

/*
Floyd建堆算法：建堆时间复杂度：O(n);

使用规则：
    1.找到最后一个非叶子节点
    2.从后向前，对每个节点执行下潜

   1.从索引0开始存储数据，则最后一个非叶子节点 i=(size/2)-1

*/
#include<iostream>
using namespace std;

//假设这次模拟是从0开始存储元素，并且是大堆顶 
//任务是：把普通数组转换为大顶堆
typedef struct queue {
    int arr[10];
    int size;
}queue;


//初始化堆
void init(queue* p) {
    p->size = 0;
}

//判断堆是否空
bool pand1(queue* p) {
    if (p->size == 0) {
        return true;
    }
    return false;
}

//判断堆是否满
bool pand2(queue* p, int maxspace) {
    if (p->size == maxspace) {
        return true;
    }
    return false;
}


//返回两个子节点最大值的下标
int retup(queue* p,int a,int b) {
    if (a>=p->size||b>=p->size||p->arr[a] >= p->arr[b]) {
        return a;
    }
    return b;
}

//交换两个元素
void swap(queue* p,int i,int j) {
    int tep = p->arr[i];
    p->arr[i] = p->arr[j];
    p->arr[j] = tep;
}

//下潜
void down(queue* p,int i) {
    int max = retup(p, 2 * i + 1, 2 * i + 2);
    while (p->arr[i] < p->arr[max]&&max<p->size) {
        swap(p, i, max);
        i = max;
        max = retup(p, 2 * i + 1, 2 * i + 2);
    }
}

//建堆
void initqueue(queue*p,int space) {
    for (int i = space / 2 - 1; i >= 0; i--) {
        down(p, i);
    }
}

//获取堆顶元素
int peek(queue* p) {
    if (pand1(p)) {
        return -1;
    }
    return p->arr[0];
}

//删除堆顶元素
void  pull(queue* p) {
    if (pand1(p)) {
        return;
    }
    swap(p, 0, p->size-1);
    p->size--;
    down( p, 0);
}

//删除指定索引处的元素
void poll(queue* p,int index) {
    if (index < 0 || index >= p->size) {
        return;
    }
    swap(p, index, p->size - 1);
    p->size--;
    down(p, index);
}

//替换堆顶元素
void puld(queue* p, int val) {
    p->arr[0] = val;
    down(p,0);
}
//元素val上浮，直至val小于父元素或者到堆顶
void up(queue* p,int val) {
    int child = p->size;
    int parent = (child - 1) / 2;
    while (p->arr[child]>p->arr[parent]&&child>0) {
        p->arr[child] = p->arr[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    p->arr[child] = val;
}

//堆尾部添加元素
void add(queue* p,int val,int space) {
    if (pand2(p, space)) {
        return;
    }
    up(p,val);
    p->size++;
}



int main() {
    queue* w = (queue*)malloc(sizeof(queue));
    init(w);
    for (int i = 0; i < 7; i++) {
        w->arr[i] = i+1;
        w->size++;
    }

    initqueue(w, 7);

    for (int j = 0; j < 7; j++) {
        cout << w->arr[j] << " ";
    }
    system("pause");
    return 0;
}