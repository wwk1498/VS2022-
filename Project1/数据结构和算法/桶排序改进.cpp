
/*
改进：解决元素分配不均匀的情况:

 1.希望桶内元素均匀分布,即桶的个数改进为 max-min+1,每个桶的索引改为 （当前值-min）
 2.希望每个桶内存储rang个元素，即减少创建桶的个数，此时桶的个数改进为 （max-min)/rang +1,每个桶的索引改为 （当前值-min)/rang


*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void bucketSort(int a[], int size,int rang) {
	//1.准备桶

	//1.1找到最大值，最小值
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	//1.2创建桶，且桶数量为：max-min+ 1
	int index = (max-min)/rang+ 1;
	vector<vector<int>> w(index);

	//2.放入数据

	for (int j = 0; j < size; j++) {
		w[(a[j] - min) / rang].push_back(a[j]);
	}

	//3.排序桶内元素,并把每个桶内排序好的数据依次放入原数组
	int m = 0;
	for (int k = 0; k < index; k++) {
		if (!w[k].empty()) {//若桶不为空，则排序桶内元素,替换原数组的元素
			sort(w[k].begin(), w[k].end());
			for (int y = 0; y < w[k].size(); y++) {
				a[m++] = w[k][y];
			}
		}
	}
}

int main() {
	int s[6] = { 12,8,3,25,7,4 };
	bucketSort(s, 6,3);
	for (int e : s) {
		cout << e << "  ";
	}
	system("pause");
	return 0;
}
