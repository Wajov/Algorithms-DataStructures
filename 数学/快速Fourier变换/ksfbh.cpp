#include <bits/stdc++.h>
using namespace std;
typedef complex<double> Complex;
const int N = 100001;
const double PI = acos(-1);
int n, m, LENG, SIZE;
double t;
Complex a[N << 2], b[N << 2], c[N << 2], ya[N << 2], yb[N << 2], yc[N << 2], yt[N << 2];
void DFT(Complex a[], Complex y[], int flag) {
    for (int i = 0; i < SIZE; i++) {
        int t = 0;
        for (int j = 0; j < LENG; j++)
            t += (i >> j & 1) << LENG - j - 1;
        y[i] = a[t];
    }
    for (int i = 1; i < SIZE; i <<= 1) {
        Complex t = polar(1.0, flag * PI / i);
        for (int j = 0; j < SIZE; j += i << 1) {
            Complex tmp = 1;
            for (int k = 0; k < i; k++) {
                yt[j + k] = y[j + k] + tmp * y[i + j + k];
                yt[i + j + k] = y[j + k] - tmp * y[i + j + k];
                tmp *= t;
            }
        }
        memcpy(y, yt, sizeof(yt));
    }
    if (flag < 0)
        for (int i = 0; i < SIZE; i++)
            y[i] /= SIZE;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &t);
        a[i] = t;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lf", &t);
        b[i] = t;
    }
    for (LENG = 0, SIZE = 1; SIZE < n + m - 1; LENG++, SIZE <<= 1);
    DFT(a, ya, 1);
    DFT(b, yb, 1);
    for (int i = 0; i < SIZE; i++)
        yc[i] = ya[i] * yb[i];
    DFT(yc, c, -1);
    for (int i = 0; i < n + m - 2; i++)
        printf("%f ", c[i].real());
    printf("%f\n", c[n + m - 2].real());
    return 0;
}
