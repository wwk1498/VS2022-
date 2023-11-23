/*
* 
希尔排序:
   1.分组实现插入，每组元素间隙称为gap
2.每轮排序后gap逐渐减小，直至gap为1完成排序
3.对插入排序的优化，让元素更快的交换到最终位置

*/

#include<iostream>
using namespace std;

//gap每次都/2
void sort1(int a[],int size) {
	
	for (int gap = size / 2; gap >= 1;gap/=2) {
		int i, key, j;
		for (int i = gap; i < size; i++) {
			key = a[i];
			j = i - gap;
			while (j >= 0 && key < a[j]) {
				a[j + gap] = a[j];
				j -= gap;
			}

			if (j!= i - gap) {
				a[j + gap] = key;
			}
			
		}
	}
}




int main() {
	int s[5] = { 34,56,1,23,9 };
	sort1(s,5);
	for (int e : s) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}