#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const double PI = acos(-1);
int n, m, LENG, SIZE;
double t;
complex<double> a[N << 2], b[N << 2], c[N << 2], ya[N << 2], yb[N << 2], yc[N << 2], yt[N << 2];
void DFT(complex<double> a[], complex<double> y[], bool flag) {
    for (int i = 0; i < SIZE; i++) {
        int t = 0;
        for (int j = 0; j < LENG; j++)
            t += (i >> j & 1) << LENG - j - 1;
        y[i] = a[t];
    }
    for (int t = 1; t < SIZE; t <<= 1) {
        double tmp = (flag ? -1 : 1) * PI / t;
        for (int i = 0; i < SIZE; i += t << 1)
            for (int j = 0; j < t; j++) {
                yt[i + j] = y[i + j] + polar(1.0, tmp * j) * y[i + t + j];
                yt[i + t + j] = y[i + j] + polar(1.0, tmp * (t + j)) * y[i + t + j];
            }
        memcpy(y, yt, sizeof(yt));
    }
    if (flag)
        for (int i = 0; i < SIZE; i++)
            y[i] /= SIZE;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &t);
        a[i] = {t, 0};
    }
    for (int i = 0; i < m; i++) {
        scanf("%lf", &t);
        b[i] = {t, 0};
    }
    for (LENG = 0, SIZE = 1; SIZE < n + m - 1; LENG++, SIZE <<= 1);
    DFT(a, ya, false);
    DFT(b, yb, false);
    for (int i = 0; i < SIZE; i++)
        yc[i] = ya[i] * yb[i];
    DFT(yc, c, true);
    for (int i = 0; i < n + m - 2; i++)
        printf("%f ", c[i].real());
    printf("%f\n", c[n + m - 2].real());
    return 0;
}
