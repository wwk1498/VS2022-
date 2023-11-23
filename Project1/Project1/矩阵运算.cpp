#include<iostream>
#include<vector>
using namespace std;

void fun(vector<vector<int>>q, vector<vector<int>>k, vector<vector<int>>ch,int n){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ch[i][j]=
		}
	}
}


int main() {
	int n, d;
	cin >> n >> d;
	vector<vector<int>>q(n,vector<int>(d, 0));
	vector<vector<int>>k(d,vector<int>(n, 0));
	vector<vector<int>>v(n,vector<int>(d, 0));
	vector<vector<int>>ch(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			int x;
			cin >> x;
			q[i][j] = x;
		}
	}
	
	for (int f = 0; f < n; f++) {
		for (int m = 0; m < d; m++) {
			int y;
			cin >> y;
			k[m][f] = y;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			int val;
			cin >> val;
			v[i][j] = val;
		}
	}
		
	for (int z = 0; z < n; z++) {
		int vlu;
		cin >> vlu;

	}
	
	system("pause");
	return 0;
}