#include<iostream>
using namespace std;
int maxArea(int *height,int size) {
	int i = 0;
	int j = size - 1;
	int area=0,max = 0;
	while (i!=j) {
		if (height[i] <= height[j]) {
			area = (j - i) * height[i];
			if (area > max) {
				max = area;
			}
			i++;
		}
		else {
			area = (j - i) * height[j];
			if (area > max) {
				max = area;
			}
			j--;
		}
	}
	return max;
}
int main() {
	int s[9] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << maxArea(s, 9) << endl;
	system("pause");
	return 0;
}