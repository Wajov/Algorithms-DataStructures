#include <bits/stdc++.h>
using namespace std;
const int N = 1000001, M = 1000001;
int n, m, u, v, tot, num, a[N], Head[N], Next[M << 1], Link[M << 1], clr[N];
bool flag[N];
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
