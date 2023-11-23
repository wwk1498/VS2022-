/*
单边循环快排（lomuto  洛穆托分区方案）

核心思想:每轮找到一个基准点元素，把比它小的放到它左边，比它大的放到它右边，这种称为分区
  1.选择最右元素作为基准点元素
  2.j指针负责找到比基准点小的元素，一旦找到则与i进行交换
  3.i指针指向大于基准点元素的左边界，也是每次交换的目标索引
  4.最后基准点与i交换，i即为分区位置

分区要点：
   1.选择最右侧元素作为基准点
   2.j找比基准点小的，i找比基准点大的，一旦找到，二者进行交换
   3.最后基准点与i交换，i即为基准点最终索引
*/

#include<iostream>
#include<random>
using namespace std;


//生成随机数
int random1(int a, int b) {

	// 创建随机数生成器
	random_device rd;
	mt19937 gen(rd());

	// 创建均匀分布对象
	uniform_int_distribution<> dis(a, b);

	// 生成随机数
	int randomNum = dis(gen);
	return randomNum;
}


//交换两个元素值
void swap(int a1[],int a,int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}

//分区并返回基准点元素索引
int partition(int a[], int left, int right) {

	//用生成随机数作为基准点
	int index = random1(left, right);
	swap(a, right, index);//交换right和index

	int pv = a[right];//基准点元素值，right为基准点索引
	int i = left;//找比pv大的元素值
	int j = left;//找比pv小的元素值
	while (j<right) {
		if (a[j]<pv) {//j找到比基准点元素小的了，没找到大的
			if (i != j) {
				swap(a, i, j);
			}
			i++;
		}
		j++;
	}
	swap(a, i, right);
	return i;//此时i为基准点索引
}


//快排--left=0,right=size-1
void quicksort(int a[],int left,int right) {

	//当left==right时，
	if (left >= right) {
		return;
	}
	//旧的基准点元素索引为right
	int p = partition(a,left,right);//p代表返回的新的基准点元素索引
	quicksort(a, left, p - 1);
	quicksort(a, p + 1, right);
}


int main() {
	int s[8] = { 3,45,1,38,89,29,21,90 };
	quicksort(s, 0,7);
	for (int e : s) {
		cout << e << " ";
	}




	system("pause");
	return 0;
}