/*
适合数据量较大的数据结构，此时时间复杂度较低
*/
#include<iostream>
using namespace std;


//正常插入排序---时间复杂度O(n2)  //left=0,right=size-1
void charu1(int a[],int left,int right) {//n是数组长度
	int i, key, j;
	for (i = left+1; i <=right; i++) {
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


//合并两个有序数组---非递归     a1--原数组，a2--新数组，k--新数组索引
//i--原数组左部分起始索引，iend--原数组左部分最后索引，j--原数组右部分起始索引，jend--原数组右部分最后索引

void merge(int a1[], int i, int iend, int j, int jend, int a2[], int k) {
	while (i <= iend && j <= jend) {
		if (a1[i] < a1[j]) {
			a2[k] = a1[i];
			i++;
		}
		else {
			a2[k] = a1[j];
			j++;
		}
		k++;
	}
	//i没走完
	while (i <= iend) {
		a2[k] = a1[i];
		i++;
		k++;
	}
	//j没走完
	while (j <= jend) {
		a2[k] = a1[j];
		j++;
		k++;
	}
}



//归并排序--递归（自上而下）---left=0,right=size-1,k=0
void split(int a1[], int left, int right, int a2[], int k) {

	//治
	if (right-left<=4) {
		charu1(a1, left, right);
		return;
	}

	//分
	int mid = (left + right) / 2;

	split(a1, left, mid, a2, k);
	split(a1, mid + 1, right, a2, k);

	//合
	merge(a1, left, mid, mid + 1, right, a2, k);
}


int main() {
	int s[10] = { 1,3,6,8,9,4,7,13,20,60 };
	int w[10];
	split(s, 0, 9,w, 0);
	for (int e : w) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}