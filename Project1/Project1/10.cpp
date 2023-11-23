#include<iostream>
#include<vector>
using namespace std;
vector<int> w;
bool fun(int n) {
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (n%i==0&&i!=1&&i!=n) {
			flag = false;
		}
	}
	if (flag == true) {
		return true;
	}
	return false;
}
bool fk(int i,int s) {
	if (fun(i) && s % i == 0) {
		return true;
	}
	return false;
}

void dg(int s) {
	if (fun(s)) {
		w.push_back(s);
		return;
	}
	for (int i = 2; i <=s/2; i++) {
		if (fk(i, s)) {
			w.push_back(i);
			dg(s / i);
			break;
		}
	}
}

int main() {
	
	int a, b;
	cin >> a >> b;
	for (int s = a; s <= b; s++) {
		if (fun(s)) {
			cout << s << "=" << s << endl;
			continue;
		}
		else {
			dg(s);
		}
		cout << s << "=";
		for (int i = 0; i < w.size(); i++) {
			if (i == w.size()-1) {
				cout << w[i];
				break;
			}
			else {
				cout << w[i] << "*";
			}
		}
		cout << endl;
		w.clear();
	}
	
	system("pause");
	return 0;
}