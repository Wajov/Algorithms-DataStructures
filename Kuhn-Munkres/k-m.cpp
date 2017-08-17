#include <bits/stdc++.h>
using namespace std;
int n, m, t, ans, a[101][101], lx[101], ly[101], slack[101], p[101];
bool fx[101], fy[101];
bool DFS(int x)
{
    fx[x] = true;
    for (int i = 1, t; i <= m; i++)
        if (!fy[i])
        {
            t = lx[x] + ly[i] - a[x][i];
            if (!t)
            {
                fy[i] = true;
                if (p[i] == 0 || DFS(p[i]))
                {
                    p[i] = x;
                    return true;
                }
            }
            else
                slack[i] = min(slack[i], lx[x] + ly[i] - a[x][i]);
        }
    return false;
}
bool Find(int x)
{
    memset(fx, false, sizeof(fx));
    memset(fy, false, sizeof(fy));
    return DFS(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        lx[i] =  INT_MIN;
        for (int j = 1; j <= m; j++)
            lx[i] = max(lx[i], a[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            slack[j] = INT_MAX;
        while (!Find(i))
        {
            t = INT_MAX;
            for (int j = 1; j <= m; j++)
                if (!fy[j])
                    t = min(t, slack[j]);
            for (int j = 1; j <= n; j++)
                if (fx[j])
                    lx[j] -= t;
            for (int j = 1; j <= m; j++)
                if (fy[j])
                    ly[j] += t;
                else
                    slack[j] -= t;
        }
    }
    for (int i = 1; i <= m; i++)
        if (p[i])
            ans += a[p[i]][i];
    printf("%d\n", ans);
    return 0;
}
