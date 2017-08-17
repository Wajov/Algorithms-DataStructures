#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, tot, num, a[1000001], Head[1000001], Next[2000001], Link[2000001], clr[1000001];
bool flag[1000001];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS1(int x)
{
    flag[x] = true;
    for (int i = Head[x], j; i; i = Next[i])
        if (i % 2 == 1 && !flag[j = Link[i]])
            DFS1(j);
    a[num--] = x;
}
void DFS2(int x)
{
    flag[x] = false;
    clr[x] = num;
    for (int i = Head[x], j; i; i = Next[i])
        if (i % 2 == 0 && flag[j = Link[i]])
            DFS2(j);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    num = n;
    for (int i = 1; i <= n; i++)
        if (!flag[i])
            DFS1(i);
    for (int i = 1; i <= n; i++)
        if (flag[a[i]])
        {
            num++;
            DFS2(a[i]);
        }
    for (int i = 1; i < n; i++)
        printf("%d ", clr[i]);
    printf("%d\n", clr[n]);
    return 0;
}
