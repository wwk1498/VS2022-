/*
时间复杂度 ： 2*n+k
要点：
   1.让原始数组映射到 count[0] ,最大值映射到 count 最右侧
   2.新数组大小为 （最大值-最小值）+1
   3.count索引 = 原始数组元素-最小值
      
*/

#include<iostream>
#include <cstdlib>//calloc函数头文件
using namespace std;

void sort1(int arr[], int size) {

	//选出最大值
	int max = arr[0];
	int min= arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	//calloc函数将分配大小为(max + 1) * sizeof(int)的内存块，并将每个字节都初始化为0。
	int* count = (int*)calloc(max-min + 1, sizeof(int));

	//根据原始数组对新数组进行元素统计
	for (int j = 0; j < size; j++) {
		int m = arr[j];
		count[m-min]++;
	}
	
	int f = 0;
	for (int k = 0; k < max-min + 1; k++) {
		while (count[k] > 0) {
			arr[f++] = k + min;
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