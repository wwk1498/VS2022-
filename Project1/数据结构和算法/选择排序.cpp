/*

选择排序：每一轮选择，求出最大（最小）的元素，并把它交换到合适的位置
         选择轮数：length-1
		 交换的索引位置，初始：length-1,每次递减
*/

#include<iostream>
using namespace std;

//非递归---->j=length-1
void xaunze(int a[], int j) {

	for (int right = j; right > 0; right--) {
		int max = right;
		for (int i = 0; i < right; i++) {
			if (a[i] > a[max]) {
				max =i;
			}
		}

		//找到最大值的索引，将元素与索引right对应的元素交换
		if (max != right) {//若最大值索引不变，则不需要交换
			int tep = a[max];
			a[max] = a[right];
			a[right] = tep;
		}
		
	}
}


int main() {

	int arr[] = { 4,56,1,234,9,89,41,8,398 };
	xaunze(arr,8);
	for (int e : arr) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}