#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, u, v, num, tot, Head[N], Next[N << 1], Link[N << 1], d[N], f[N], s[N], son[N], top[N], idx[N], key[N];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS1(int x)
{
    d[x] = d[f[x]] + 1;
    s[x] = 1;
    for (int i = Head[x], j; i; i = Next[i])
        if (!d[j = Link[i]])
        {
            f[j] = x;
            DFS1(j);
            s[x] += s[j];
            if (s[j] > s[son[x]])
                son[x] = j;
        }
}
void DFS2(int x)
{
    top[x] = x == son[f[x]] ? top[f[x]] : x;
    key[idx[x] = ++num] = x;
    if (son[x])
        DFS2(son[x]);
    for (int i = Head[x], j; i; i = Next[i])
    {
        j = Link[i];
        if (f[j] == x && j != son[x])
            DFS2(j);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    DFS1(1);
    DFS2(1);
    for (int i = 1; i < n; i++)
        printf("%d ", key[i]);
    printf("%d\n", key[n]);
    return 0;
}
