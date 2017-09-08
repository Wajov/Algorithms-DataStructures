#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, SIZE, u, v, tot, num, a[N], d[N], f[N], s[N], son[N], top[N], idx[N], Head[N], Next[N << 1], Link[N << 1], sum[N << 2];
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
    idx[x] = ++num;
    if (son[x])
        DFS2(son[x]);
    for (int i = Head[x], j; i; i = Next[i])
    {
        j = Link[i];
        if (f[j] == x && j != son[x])
            DFS2(j);
    }
}
void TBuild()
{
    for (SIZE = 1; SIZE < n + 2; SIZE <<= 1);
    for (int i = 1; i <= n; i++)
        sum[SIZE + idx[i]] = a[i];
    for (int i = SIZE - 1; i; i--)
        sum[i] = sum[i << 1] + sum[(i << 1) + 1];
}
void TAdd(int x, int y)
{
    for (x += SIZE; x; x >>= 1)
        sum[x] += y;
}
int TSum(int x, int y)
{
    int ans = 0;
    for (x += SIZE - 1, y += SIZE + 1; x ^ y ^ 1; x >>= 1, y >>= 1)
    {
        if ((x & 1) == 0)
            ans += sum[x ^ 1];
        if ((y & 1) == 1)
            ans += sum[y ^ 1];
    }
    return ans;
}
void Add(int x, int y)
{
    TAdd(idx[x], y);
}
int Sum(int x, int y)
{
    int u, v, ans = 0;
    while ((u = top[x]) != (v = top[y]))
        if (d[u] > d[v])
        {
            ans += TSum(idx[u], idx[x]);
            x = f[u];
        }
        else
        {
            ans += TSum(idx[v], idx[y]);
            y = f[v];
        }
    if (d[x] > d[y])
        swap(x, y);
    return ans += TSum(idx[x], idx[y]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    DFS1(1);
    DFS2(1);
    return 0;
}
