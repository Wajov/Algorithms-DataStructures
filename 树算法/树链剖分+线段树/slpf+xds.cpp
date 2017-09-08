#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, u, v, tot, num, a[N], d[N], f[N], s[N], son[N], top[N], idx[N], key[N], Head[N], Next[N << 1], Link[N << 1], l[N << 1], r[N << 1], sum[N << 1], lab[N << 1];
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
inline void TDown(int p, int x, int y)
{
    if (x < y)
    {
        int z = x + y >> 1;
        sum[l[p]] += lab[p] * (z - x + 1);
        sum[r[p]] += lab[p] * (y - z);
        lab[l[p]] += lab[p];
        lab[r[p]] += lab[p];
    }
    lab[p] = 0;
}
inline void TUp(int p)
{
    sum[p] = sum[l[p]] + sum[r[p]];
}
void TBuild(int p, int x, int y)
{
    if (x == y)
    {
        sum[p] = a[key[x]];
        return;
    }
    int z = x + y >> 1;
    TBuild(l[p] = ++num, x, z);
    TBuild(r[p] = ++num, z + 1, y);
    TUp(p);
}
void TAdd(int p, int x, int y, int a, int b, int c)
{
    TDown(p, x, y);
    if (x == a && y == b)
    {
        sum[p] += c * (y - x + 1);
        lab[p] += c;
        return;
    }
    int z = x + y >> 1;
    if (b <= z)
        TAdd(l[p], x, z, a, b, c);
    else if (a > z)
        TAdd(r[p], z + 1, y, a, b, c);
    else
    {
        TAdd(l[p], x, z, a, z, c);
        TAdd(r[p], z + 1, y, z + 1, b, c);
    }
    TUp(p);
}
int TSum(int p, int x, int y, int a, int b)
{
    TDown(p, x, y);
    if (x == a && y == b)
        return sum[p];
    int z = x + y >> 1;
    if (b <= z)
        return TSum(l[p], x, z, a, b);
    else if (a > z)
        return TSum(r[p], z + 1, y, a, b);
    else
        return TSum(l[p], x, z, a, z) + TSum(r[p], z + 1, y, z + 1, b);
}
void Add(int x, int y, int z)
{
    int u, v;
    while ((u = top[x]) != (v = top[y]))
        if (d[u] > d[v])
        {
            TAdd(1, 1, n, idx[u], idx[x], z);
            x = f[u];
        }
        else
        {
            TAdd(1, 1, n, idx[v], idx[y], z);
            y = f[v];
        }
    if (d[x] > d[y])
        swap(x, y);
    TAdd(1, 1, n, idx[x], idx[y], z);
}
int Sum(int x, int y)
{
    int u, v, ans = 0;
    while ((u = top[x]) != (v = top[y]))
        if (d[u] > d[v])
        {
            ans += TSum(1, 1, n, idx[u], idx[x]);
            x = f[u];
        }
        else
        {
            ans += TSum(1, 1, n, idx[v], idx[y]);
            y = f[v];
        }
    if (d[x] > d[y])
        swap(x, y);
    return ans += TSum(1, 1, n, idx[x], idx[y]);
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
    num = 1;
    return 0;
}
