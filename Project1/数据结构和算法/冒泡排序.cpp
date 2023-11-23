#include<iostream>
using namespace std;
/*
* 递归冒泡排序

1.将数组分成两部分  [0......j][j+1.....length-1]
2.左边是未排序部分，右边是已排序部分，在未排序区间内，相邻两个元素比较，如果前一个大于后一个，则交换位置
* 
* 
*
* 冒泡排序: 
  把数组分为左边：未排序数组，右边：已排序数组
* 若数组长度len=n; 则需要循环 i=n-1 次，每一次循环则把 未排序数组 的（最大值或最小值）推到 已排序数组
* 而每一次循环需要相邻两个元素进行对比 j=n-1-i 次,然后交换位置；
*/

//正常冒泡排序-------时间复杂度O(n^2)(尽量不要用）
void fun(int a[],int end) {//end---数组最后一个元素的索引
	for (int i = 0; i < end ; i++) {
		for (int j = 0; j < end - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


//非递归冒泡排序---j=a.length-1
void bubble(int a[],int j) {

	while (true) {
		int x = 0;
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				x = i;
			}
		}
		j = x;
		if (j == 0) {
			break;
		}
	}
}




//一般递归实现冒泡排序---j=a.length-1
void digui(int a[], int j) {
	if (j == 0) {
		return;
	}
	for (int i = 0; i < j; i++) {
		if (a[i] > a[i + 1]) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
	digui(a,j-1);
}

//改进的递归实现冒泡排序(当左边已经排序时，无需再判断，减少循环次数)---j=a.length-1
void diguix(int a[], int j) {
	if (j == 0) {
		return;
	}
	int x = 0;
	for (int i = 0; i < j; i++) {
		if (a[i] > a[i + 1]) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
			x = i;
		}
	}
	diguix(a, x);
}



int main() {
	
	int arry[] = { 12,4,2,78,35,9 };

	digui(arry,5);

	for (int i = 0; i < 6; i++) {
		cout << arry[i] << "  ";
	}

	cout << endl;
	cout << "--------------------------" << endl;

	int appy[] = { 102,4,2,78,3,9 };

	diguix(appy, 5);

	for (int j = 0; j < 6; j++) {
		cout << appy[j] << "  ";
	}

	cout << endl;
	cout << "--------------------------" << endl;


	int cs[] = { 34,56,2,9,789,29 };
	bubble(cs,5);
	for (int e : cs) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}
