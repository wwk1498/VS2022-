#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int>w;
vector<double>q;
vector<double> p;


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        double b;
        cin >> a;
        cin >> b;
        w.push_back(a);
        q.push_back(b);
        
    }

    for (int j = 0; j < m; j++) {
        int c1, c2;
        double x, y;
        cin >> c1 >> c2 >> x >> y;
        for (int g = c1 - 1; g < c2; g++) {
            int index = w[g];
            if (index == 1) {
                double k = q[g];
                x = x * k;
                y = y * k;
            }
            else {
                double r = q[g];
                double x2 = x;
                double y2 = y;
                x = x2 * cos(r) - y2 * sin(r);
                y = x2 * sin(r) + y2 * cos(r);
            }
        }
        p.push_back(x);
        p.push_back(y);
    }
    for (int l = 0; l < p.size(); l+=2) {
        printf("%.3lf %.3lf\n",p[l],p[l+1]);
    }
    
    system("pause");
    return 0;
}