#include<iostream>
using namespace std;
//方法1
int fun(int arry[], int targe, int size) {
	int i = 0, j =size-1;
	while (i <= j) {
		//int m = (i + j) >> 1   ---->  存在溢出风险，当i或者j较大时，m会出错
		int m = i + ((j - i) >> 1);//int m =i+ ((j-i) >> 1)  ---->  可以保证m一定大于i，小于j
		if (targe < arry[m]) {
			j = m - 1;
		}
		else if (arry[m] < targe) {
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}
//方法2
int func(int arry[], int targe, int size) {
	int i = 0, j = size;
	while (i < j) {
		int m = i + ((j - i) >> 1);
		if (targe < arry[m]) {
			j = m;
		}
		else if (arry[m] < targe) {
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}
//方法3-->平衡板
 int binarySearchBalance(int a[], int target, int size) {
	int i = 0, j = size;
	while (1 < j - i) {         // 范围内待查找的元素个数 > 1 时
		int m = i + ((j - i) >> 1);
		if (target < a[m]) {    // 目标在左边
			j = m;
		}
		else {                // 目标在 m 或右边
			i = m;
		}
	}
	return (target == a[i]) ? i : -1;
}

 //方法4  --->leftmost----->寻找目标值最左的索引
 int funu(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 int candidate = -1;//候选者
	 while (i <= j) {
		 int m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else if (arry[m] < targe) {
			 i = m + 1;
		 }
		 else { 
			 candidate = m;//候选者标记
			 j = m - 1;
		 }
	 }
	 return candidate;
 }
 //方法5  --->rightmost----->寻找目标值最右的索引
 int funp(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 int candidate = -1;//候选者
	 while (i <= j) {
		 int m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else if (arry[m] < targe) {
			 i = m + 1;
		 }
		 else {
			 candidate = m;//候选者标记
			 i = m + 1;
		 }
	 }
	 return candidate;
 }

 //方法6  --->leftmost  ---->返回  大于等于targe 的最靠左索引
 int funk(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 while (i <= j) {
		 int  m = i + ((j - i) >> 1);
		 if (targe <= arry[m]) {
			 j = m - 1;
		 }else{
			 i = m + 1;
		 }
	 }
	 return i;
 }
 //方法7  --->rightmost  ---->返回  小于等于targe 的最靠右索引
 int funj(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 while (i <= j) {
		 int  m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else {
			 i = m + 1;
		 }
	 }
	 return i-1;
 }

int main(void) {
	int arry[12] = { 1,2,3,4,5,5,7,8,8,8,9,10 };
	int size= sizeof(arry) / sizeof(arry[0]);
	int target = -3;
	//cout << size << endl;
	//int maxValue = std::numeric_limits<int>::max();
	//cout << fun(arry, target, size) << endl;
	//cout << func(arry, target, size) << endl;
	cout << funp(arry, target, size) << endl;
	system("pause");
	return 0;
}