#include <bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001], sum[100001], tmp[100001], id[100001], rk[100010];
char s[100010];
void Sort(int a[], int m)
{
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
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[id[i] = i] = s[i] - 97;
    Sort(a, 25);
    for (int i = 1; i <= n; i <<= 1)
    {
        for (int j = 1, t = 0; j <= n; j++)
            rk[id[j]] = a[id[j]] == a[id[j - 1]] && b[id[j]] == b[id[j - 1]] ? t : ++t;
        for (int j = 1; j <= n; j++)
        {
            a[j] = rk[j];
            b[j] = rk[min(i + j, n + 1)];
        }
        Sort(b, n);
        Sort(a, n);
    }
    for (int i = 1; i < n; i++)
        printf("%d ", rk[i]);
    printf("%d\n", rk[n]);
    return 0;
}
