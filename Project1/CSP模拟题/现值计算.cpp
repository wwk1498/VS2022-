#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	double m;
	cin >> n;
	cin >> m;
	double sum = 0;
	int num[50] ;
	
	for (int i = 0; i < n + 1; i++) {
		cin >> num[i];
	}

	for (int j = 1; j <n+1; j++) {
		sum += num[j] *1.0* pow(1+m,-j);
	}
	sum += num[0];
	printf("%.3f\n", sum);
	system("pause");
	return 0;
}