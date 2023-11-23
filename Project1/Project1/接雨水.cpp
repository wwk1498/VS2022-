#include<iostream>
using namespace std;
int trap(int* height, int size) {
	int i = 0;
	int j = i+1;
	int sum = 0;
	while (j!=size) {
		if (height[i] < height[j]) {
			i = j;
			j++;
		}
		else if (height[i] > height[j]) {
			j++;
		}
	}
}
int main() {

	system("pause");
	return 0;
}