/*
插入排序：左边为已排序[0...low-1]，右边为未排序[low....length-1], 时间复杂度O(n)
每次取右边最靠左的未排序的元素依次与左边最靠右的已排序的元素对比，若大于，则位置不动，若小于，则交换位置
初始：令low=1,t=a[low],i=low-1;
*/

#include<iostream>
using namespace std;

//正常插入排序---时间复杂度O(n2)
void charu1(int a[],int n) {//n是数组长度
	int i, key, j;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j>=0&&key < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		if (j != i - 1) {
			a[j + 1] = key;
		}
	}
}

//递归实现插入排序
void charu2(int a[],int low,int len) {//low=1，len=数组长度
	if (low == len) {
		return;
	}
	int t = a[low];
	int i = low - 1;
	while (i>=0&&t<a[i]) {
		a[i + 1] = a[i];
		i--;
	}
	if (i != low - 1) {
		a[i + 1] = t;
	}
	charu2(a, low + 1,len);
}

int main(void) {
	int p[] = { 12,45,2,6,89,23};
	charu1(p,6);
	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
		cout << p[i] << "  ";
	}

	system("pause");
	return 0;
}
