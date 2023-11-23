#include<iostream>
#include<vector>
using namespace std;
vector<int> w;
int main() {
    int n,p,min,max,sum=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        sum += p;
        w.push_back(p);
   }
    min =max= w[0];
    for (int j = 0; j < n; j++) {
        if (w[j] < min) {
            min = w[j];
        }
        if (w[j] > max) {
            max = w[j];
        }
    }
    
    double f = (sum - min - max) / ((n - 2) * 1.0);
    printf("%.2lf",f);
    system("pause");
    return 0;
}