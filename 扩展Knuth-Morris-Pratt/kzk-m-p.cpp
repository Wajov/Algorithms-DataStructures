#include <bits/stdc++.h>
using namespace std;
int n, m, p[1000001], ex[1000001];
char a[1000010], b[1000010];
int main()
{
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    for (int i = 2, j = 0; i <= m; i++)
        {
            for (p[i] = i < j + p[j] ? min(p[i - j + 1], j + p[j] - i) : 0; i + p[i] <= m && b[i + p[i]] == b[p[i] + 1]; p[i]++);
            if (i + p[i] > j + p[j])
                j = i;
        }
        for (int i = 1, j = 0; i <= n; i++)
        {
            for (ex[i] = i <= j + ex[j] ? min(p[i - j + 1], j + ex[j] - i) : 0; i + ex[i] <= n && ex[i] < m && a[i + ex[i]] == b[ex[i] + 1]; ex[i]++);
            if (i + ex[i] > j + ex[j])
                j = i;
        }
    for (int i = 1; i < n; i++)
        printf("%d ", ex[i]);
    printf("%d\n", ex[n]);
    return 0;
}
