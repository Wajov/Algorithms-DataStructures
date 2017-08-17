#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, tot, ans, Head[1001], Next[10001], Link[10001], p[1001];
bool flag[1001];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
bool DFS(int x)
{
    for (int i = Head[x], j; i; i = Next[i])
        if (!flag[j = Link[i]])
        {
            flag[j] = true;
            if (p[j] == 0 || DFS(p[j]))
            {
                p[j] = x;
                return true;
            }
        }
    return false;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(flag, false, sizeof(flag));
        if (DFS(i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
