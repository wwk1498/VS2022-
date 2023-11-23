#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> k1;
vector<int> k2;
vector<int> d = { 1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1 };//d3=d[3*2],d[3*2+1]
priority_queue<int,vector<int>,greater<int>> myque;


//返回龙到达边界的最小运动距离
int binajie(int u,int v) {
	int x1 = u - 1;
	int x2 = 7 - u;
	int y1 = v - 1;
	int y2 = 7 - v;

	myque.push(x1);
	myque.push(x2);
	myque.push(y1);
	myque.push(y2);

	return myque.top();
}

//判断坐标是否在d里面
bool zb(int a,int b,int dis) {
	for (int i = 0; i < d.size(); i+=2) {
		if (a== d[i]*dis && b== d[i + 1]*dis) {
			return true;
		}
	}
	return false;
}


//龙运动过程
void yund(int n,int m,int u, int v, int t, vector<int> w1, vector<vector<int>>w3, vector<int> d) {
	int dis = 1;
	int k = 7;
	while (dis<= binajie(u, v)) {
		for (int i = 0; i < w1.size(); i += 2) {
			int x = w1[i];
			int y = w1[i + 1];
			int xm = x - u;
			int ym = y - v;
			if (zb(xm, ym,dis)) {
				k1.push_back(dis);
				break;
			}
		}
		dis++;
	}

	int dbj = binajie(u, v);
	while (dbj!=0) {
		k2.push_back(dbj);
		dbj--;
	}

	for (int e : k1) {
		for (int m : k2) {
			if (e==m&&e<k) {
				k = e;
			}
		}
	}
	if (k==7) {
		k = 0;
	}
	//进行旋转
	for (int c = 0; c < w1.size(); c += 2) {
		for (int s = 0; s < d.size(); s+=2) {
			if (u + d[s]*k==w1[c] && v+d[s+1]*k==w1[c+1]){
				//交换员工位置

				break;
			}
		}
	}
	
}

int main() {
	int n, m, p,q;
	cin >>n >> m>>p>>q;
	vector<int> w1;//员工个人位置
	vector<int> w2;//阴阳龙位置和强度
	vector<vector<int>>w3(m, vector<int>(n,0));//员工二维
	int count = 1;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		w1.push_back(x);
		w1.push_back(y);
		w3[x][y] = count++;
	}

	for (int j = 0; j < q; j++) {
		int u, v, t;
		cin >> u >>v >> t;
		yund(n,m,u,v,t,w1,w3,d);


	}






	system("pause");
	return 0;
}