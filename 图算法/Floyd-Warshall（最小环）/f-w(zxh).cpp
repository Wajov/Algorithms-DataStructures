#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, m, u, v, c, t, num, Min, a[N][N], d[N][N], p[N][N], ans[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = i == j ? 0 : INT_MAX / 3;
            p[i][j] = i;
        }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        a[u][v] = a[v][u] = min(a[u][v], c);
    }
    memcpy(d, a, sizeof(d));
    Min = INT_MAX / 3;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = 1; j < i; j++)
                if (d[i][j] + a[i][k] + a[k][j] < Min)
                {
                    Min = d[i][j] + a[i][k] + a[k][j];
                    for (num = 0, t = j; t != i; t = p[i][t])
                        ans[++num] = t;
                    ans[++num] = i;
                    ans[++num] = k;
                }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
    }
    printf("%d\n", Min);
    for (int i = 1; i < num; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[num]);
    return 0;
}
