#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, SIZE, a[N << 1], b[N << 1], c[N << 1], ya[N << 1], yb[N << 1], yc[N << 1];
void WHT(int a[], int y[], int flag) {
    for (int i = 0; i < SIZE; i++)
        y[i] = a[i];
    for (int i = 1; i < SIZE; i <<= 1)
        for (int j = 0; j < SIZE; j += i << 1)
            for (int k = 0; k < i; k++) {
                int t1 = y[j + k], t2 = y[i + j + k];
                y[j + k] = t1 + t2;
                y[i + j + k] = t1 - t2;
                if (flag == -1) {
                    y[j + k] >>= 1;
                    y[i + j + k] >>= 1;
                }
            }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (SIZE = 1; SIZE < max(n, m); SIZE <<= 1);
    WHT(a, ya, 1);
    WHT(b, yb, 1);
    for (int i = 0; i < SIZE; i++)
        yc[i] = ya[i] * yb[i];
    WHT(yc, c, -1);
    for (int i = 0; i < SIZE - 1; i++)
        printf("%d ", c[i]);
    printf("%d\n", c[SIZE - 1]);
    return 0;
}
