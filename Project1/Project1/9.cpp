#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<double> xita(100005);
vector<double> k(100005, 1);


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int type;
        double value;
        cin >> type >> value;
        if (type == 1) {
            k[i] = k[i - 1] * value;
            xita[i] = xita[i - 1];
        }
        else {
            k[i] = k[i - 1];
            xita[i] = xita[i - 1] + value;
        }
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        double x, y;
        cin >> l >> r >> x >> y;

        double sum_xita = xita[r] - xita[l - 1];
        double pro_k = k[r] / k[l - 1];

        cout << fixed << setprecision(3) << (x * cos(sum_xita) - y * sin(sum_xita)) * pro_k << " "
            << (x * sin(sum_xita) + y * cos(sum_xita)) * pro_k << endl;
    }

    return 0;
}