#include<iostream>
#include<random>
using namespace std;

/*
适合大量数据
*/


//正常插入排序---时间复杂度O(n2)
void charu1(int a[], int left, int right) {//n是数组长度
	int i, key, j;
	for (i = left + 1; i <= right; i++) {
		key = a[i];
		j = i - 1;
		while (j >= left && key < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		if (j != i - 1) {
			a[j + 1] = key;
		}
	}
}

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
void swap(int a1[], int a, int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}


//分区并返回基准点元素索引
int partition(int a[], int left, int right) {

	//用生成随机数作为基准点
	int index = random1(left, right);
	swap(a, left, index);//交换left和index


	int pv = a[left];//基准点元素值，left为基准点索引
	int i = left + 1;//找大于等于pv的元素值
	int j = right;//找小于等于pv的元素值
	while (i <= j) {
		//j从右向左
		while (i <= j && a[j] > pv) {
			j--;
		}
		//i从左向右
		while (i <= j && a[i] < pv) {
			i++;
		}
		if (i <= j) {
			swap(a, i, j);
			i++;
			j--;
		}

	}
	swap(a, j, left);
	return j;//此时i为基准点索引
}


//快排--left=0,right=size-1
void quicksort(int a[], int left, int right) {

	//当left>=right时，
	if (right-left<=5) {
		charu1(a,left,right);
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