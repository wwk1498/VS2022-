/*

计数排序要点:
 1.找到最大值，创建一个大小为最大值+1的count数组
 2.count数组的索引对应原始数组的元素，用来统计该元素的出现次数
 3.遍历count数组，根据count数组的索引（即原始数组的元素）以及出现次数，生成排序后内容，count数组的索引是:
   已排好序的
 前提:待排序元素>=0且最大值不能太大

*/

#include<iostream>
#include <cstdlib>//calloc函数头文件
using namespace std;

void sort1(int arr[],int size) {

	//选出最大值
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i]>max) {
			max = arr[i];
		}
	}
	
	//calloc函数将分配大小为(max + 1) * sizeof(int)的内存块，并将每个字节都初始化为0。
	int* count = (int*)calloc(max + 1, sizeof(int));

	//根据原始数组对新数组进行元素统计
	for (int j = 0; j < size; j++) {
		int m = arr[j];
		count[m]++;
	}
	
	int f=0;
	for (int k = 0; k < max + 1; k++) {
		while (count[k]>0) {
			arr[f++] = k;
			count[k]--;
		}
	}

	free(count);
}


int main() {

	int a[8] = { 2,5,9,1,3,2,4,2 };
	sort1(a, 8);
	for (int e : a) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}