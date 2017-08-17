#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, tot, num, Head[1000001], Next[2000001], Link[2000001], ans[1000001];
bool flag[1000001];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS(int x)
{
    flag[x] = true;
    for (int i = Head[x], j; i; i = Next[i])
        if (!flag[j = Link[i]])
            DFS(j);
    ans[++num] = x;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!flag[i])
            DFS(i);
    for (int i = n; i > 1; i--)
        printf("%d ", ans[i]);
    printf("%d\n", ans[1]);
    return 0;
}
