#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double* la = new double[100000];//����
    double* jd = new double[100000];//�Ƕ�
    la[0] = 1.0;
    jd[0] = 0.0;
    
    for (int i = 1; i <= n; i++) {
        int a;
        double b;
        cin >> a;
        cin >> b;
        if (a == 1) {//�ǶȲ���
            la[i] = la[i - 1]*b;
            jd[i] = jd[i - 1];
        }
        else {//���첻��
            la[i] = la[i - 1];
            jd[i] = jd[i - 1] + b;
        }
    }

    for (int j = 0; j < m; j++) {
        int c1, c2;
        double x, y;
        cin >> c1 >> c2 >> x >> y;
        double lam = la[c2] / la[c1-1];
        double jdm = jd[c2] - jd[c1-1];
        printf("%.3lf %.3lf\n", (x * cos(jdm) - y * sin(jdm)) * lam, (x * sin(jdm) + y * cos(jdm)) * lam);
    }
    
    system("pause");
    return 0;
}

