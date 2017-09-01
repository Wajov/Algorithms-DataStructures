#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, k, u, v, tot, ans, Head[N], Next[M], Link[M], p[N];
bool flag[N];
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
