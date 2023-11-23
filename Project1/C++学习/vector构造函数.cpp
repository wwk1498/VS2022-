#include<iostream>
#include<vector>
using namespace std;
void pringvet(vector<int> k) {
	for (vector<int>::iterator v1 = k.begin(); v1 != k.end(); v1++) {
		cout << *v1 << " ";
	}
	cout << endl;
}
void test() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	pringvet(v);
	vector <int> v2(v.begin(), v.end());
	vector<int> v3(v2);
	vector<int> v4(10,56);

	pringvet(v2);
	pringvet(v3);
	pringvet(v4);

	vector<int> v5;
	v5.assign(v.begin(), v.end());
	pringvet(v5);

	if (v5.empty()) {
		cout << 0 <<endl;
	}
	else {
		cout << 1 << endl;
	}
	cout << v5.capacity() << endl;//容量
	cout << v5.size()<< endl;//大小
	v5.resize(15);//重新指定大小
	pringvet(v5);

	v5.resize(10, 10);//利用重载，重新指定默认填充
	pringvet(v5);

}
int main() {
	test();
	system("pause");
	return 0;
}