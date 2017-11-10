#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, a[N], b[N], sum[N], tmp[N], id[N], rk[N + 10];
char s[N + 10];
void Sort(int a[], int m) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
        sum[a[i]]++;
    for (int i = 1; i <= m; i++)
        sum[i] += sum[i - 1];
    for (int i = n; i; i--)
        tmp[id[i]] = sum[a[id[i]]]--;
    for (int i = 1; i <= n; i++)
        id[tmp[i]] = i;
}
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[id[i] = i] = s[i] - 96;
    Sort(a, 26);
    for (int i = 1, t = 0; i <= n; i++)
        rk[id[i]] = a[id[i]] == a[id[i - 1]] ? t : ++t;
    for (int i = 1; i <= n; i <<= 1) {
        for (int j = 1; j <= n; j++) {
            a[j] = rk[j];
            b[j] = rk[min(i + j, n + 1)];
        }
        Sort(b, n);
        Sort(a, n);
        for (int j = 1, t = 0; j <= n; j++)
            rk[id[j]] = a[id[j]] == a[id[j - 1]] && b[id[j]] == b[id[j - 1]] ? t : ++t;
    }
    for (int i = 1; i < n; i++)
        printf("%d ", rk[i]);
    printf("%d\n", rk[n]);
    return 0;
}
