#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100001, MOD = 998244353;
int n, m, LENG, SIZE, a[N << 2], b[N << 2], c[N << 2], ya[N << 2], yb[N << 2], yc[N << 2], yt[N << 2];
int Pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ll)ans * a % MOD;
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return ans;
}
void NTT(int a[], int y[], int flag) {
    for (int i = 0; i < SIZE; i++) {
        int t = 0;
        for (int j = 0; j < LENG; j++)
            t += (i >> j & 1) << LENG - j - 1;
        y[i] = a[t];
    }
    for (int i = 1; i < SIZE; i <<= 1) {
        int t = Pow(3, (MOD - 1 + flag * (MOD - 1) / (i << 1)) % (MOD - 1));
        for (int j = 0; j < SIZE; j += i << 1) {
            int tmp = 1;
            for (int k = 0; k < i; k++) {
                yt[j + k] = (y[j + k] + (ll)tmp * y[i + j + k]) % MOD;
                yt[i + j + k] = (y[j + k] + (ll)(MOD - tmp) * y[i + j + k]) % MOD;
                tmp = (ll)tmp * t % MOD;
            }
        }
        memcpy(y, yt, sizeof(yt));
    }
    if (flag < 0)
        for (int i = 0; i < SIZE; i++)
            y[i] = (ll)y[i] * Pow(SIZE, MOD - 2) % MOD;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (LENG = 0, SIZE = 1; SIZE < n + m - 1; LENG++, SIZE <<= 1);
    NTT(a, ya, 1);
    NTT(b, yb, 1);
    for (int i = 0; i < SIZE; i++)
        yc[i] = (ll)ya[i] * yb[i] % MOD;
    NTT(yc, c, -1);
    for (int i = 0; i < n + m - 2; i++)
        printf("%d ", c[i]);
    printf("%d\n", c[n + m - 2]);
    return 0;
}
