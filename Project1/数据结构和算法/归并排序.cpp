/*
归并排序
1.分-每次从中间切一刀，处理的数据少一半
2.治-当数据仅剩一个时可以认为有序
3.合-两个有序的结果，可以进行合并
*/

#include<iostream>
using namespace std;

//合并两个有序数组---非递归     a1--原数组，a2--新数组，k--新数组索引
//i--原数组左部分起始索引，iend--原数组左部分最后索引，j--原数组右部分起始索引，jend--原数组右部分最后索引

void merge(int a1[],int i,int iend,int j,int jend,int a2[],int k) {
	while (i<=iend && j<=jend) {
		if (a1[i]<a1[j]) {
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
	while(j <= jend) {
		a2[k] = a1[j];
		j++;
		k++;
	}
}

//合并两个有序数组---递归     a1--原数组，a2--新数组，k--新数组索引
//i--原数组左部分起始索引，iend--原数组左部分最后索引，j--原数组右部分起始索引，jend--原数组右部分最后索引
void merge1(int a1[], int i, int iend, int j, int jend, int a2[], int k) {

	//j没走完
	if (i>iend) {
		while (j<=jend) {
			a2[k] = a1[j];
			j++;
			k++;
		}
		return;
	}

	//i没走完
	if (j > jend) {
		while (i<=iend) {
			a2[k] = a1[i];
			i++;
			k++;
		}
		return;
	}
	if (a1[i]<a1[j]) {
		a2[k] = a1[i];
		merge1(a1, i + 1, iend, j, jend, a2, k + 1);
	}
	else {
		a2[k] = a1[j];
		merge1(a1, i, iend, j+1, jend, a2, k + 1);
	}

}


//归并排序--递归（自上而下）---left=0,right=size-1,k=0
void split(int a1[],int left ,int right,int a2[],int k) {

	//治
	if (left == right) {
		return;
	}

	//分
	int mid = (left + right) / 2;

	split(a1, left, mid,a2,k);
	split(a1,mid+1,right,a2,k);

	//合
	merge(a1, left, mid, mid+1, right, a2,k);
}

//归并排序--非递归（自下而上）
void split1(int a1[],int size,int a2[], int k) {
	for (int width = 1; width < size; width *= 2) {
		for (int left = 0; left < size; left += 2 * width) {
			int right = min(left+2*width-1,size-1);
			int mid = (left + right) / 2;
			merge(a1, left, mid, mid+1, right, a2, k);
		}
	}
}


int main() {
	int s[10] = { 1,3,6,8,9,4,7,13,20,60 };
	int w[10];
	split1(s, 10, w, 0);
	for (int e : w) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}