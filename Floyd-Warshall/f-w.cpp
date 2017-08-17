#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, c, d[101][101];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = i == j ? 0 : INT_MAX >> 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        d[u][v] = d[v][u] = min(d[u][v], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            printf("%d ", d[i][j] == INT_MAX >> 1 ? -1 : d[i][j]);
        printf("%d\n", d[i][n] == INT_MAX >> 1 ? -1 : d[i][n]);
    }
    return 0;
}
