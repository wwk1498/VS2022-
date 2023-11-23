/*
思想:
  1.把不同范围的数据分成若干小组（桶）,1-9,10-19,20-29........
  2.针对不同的桶分别进行排序，最后把排好序的数据依次放入原来的数组
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void bucketSort(int a[],int size) {
	//1.准备桶
	
	//1.1找到最大值
	int max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	//1.2创建桶，且桶数量为：max / 10 + 1
	int index = max / 10 + 1;
	vector<vector<int>> w(index);
	
	//2.放入数据
	
	for (int j = 0; j < size; j++) {
		w[a[j]/10].push_back(a[j]);
	}

	//3.排序桶内元素,并把每个桶内排序好的数据依次放入原数组
	int m = 0;
	for (int k = 0; k < index; k++) {
		sort(w[k].begin(), w[k].end());
		if (!w[k].empty()) {//若桶不为空，则替换原数组的元素
			for (int y = 0; y < w[k].size(); y++) {
				a[m++] = w[k][y];
			}
		}
		
	}
}

int main() {
	int s[6] = { 12,8,3,25,7,4 };
	bucketSort(s, 6);
	for (int e : s) {
		cout << e << "  ";
	}
	system("pause");
	return 0;
}