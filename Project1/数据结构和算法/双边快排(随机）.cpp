/*
* 
双边循环要点:
1.选择最左侧元素作为基准点
2.j找比基准点小的，i找比基准点大的，一旦找到，二者进行交换
  i从左向右
  j从右向左
3.最后基准点与i交换，i即为基准点最终索引


注意:
  1.内层循环加i<j
  2.先处理j，再处理i
  3.随机元素作为基准点（避免正序数组和逆序数组影响）
  4.如果有大量重复元素

*/

#include<iostream>
#include<random>
using namespace std;


//生成随机数
int random1(int a,int b) {
	
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
void swap(int a1[], int a, int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}


//分区并返回基准点元素索引
int partition(int a[], int left, int right) {

	//用生成随机数作为基准点
	int index = random1(left, right);
	swap(a,left,index);//交换left和index


	int pv = a[left];//基准点元素值，left为基准点索引
	int i = left;//找比pv大的元素值
	int j = right;//找比pv小的元素值
	while (i < j) {
		//j i 不能改顺序，否则出错
		//j从右向左
		while (i<j && a[j]>=pv) {
			j--;
		}
		//i从左向右
		while (i < j && a[i] <= pv) {
			i++;
		}
		if (i < j) {
			swap(a, i, j);
		}
	}
	swap(a, i, left);
	return i;//此时i为基准点索引
}


//快排--left=0,right=size-1
void quicksort(int a[], int left, int right) {

	//当left==right时，
	if (left >= right) {
		return;
	}
	//旧的基准点元素索引为right
	int p = partition(a, left, right);//p代表返回的新的基准点元素索引
	quicksort(a, left, p - 1);
	quicksort(a, p + 1, right);
}


int main() {

	int s[8] = { 3,45,1,38,89,29,21,90 };
	quicksort(s, 0, 7);
	for (int e : s) {
		cout << e << " ";
	}


	system("pause");
	return 0;
}