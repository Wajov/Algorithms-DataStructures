#include <bits/stdc++.h>
using namespace std;
int n, m, S, T, u, v, r, tot, ans, Head[1001], cur[1001], Next[20001], Link[20001], Rest[20001], From[1001], Edge[1001], d[1001];
queue<int> q;
inline void AddEdge(int u, int v, int r)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Rest[tot] = r;
    Head[u] = tot;
}
bool BFS()
{
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    d[S] = 0;
    q.push(S);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = Head[now], j; i; i = Next[i])
            if (Rest[i] > 0 && d[now] + 1 < d[j = Link[i]])
            {
                d[j] = d[now] + 1;
                q.push(j);
            }
    }
    return d[T] < INT_MAX;
}
bool DFS(int x)
{
    if (x == T)
    {
        int tmp = INT_MAX;
        for (int i = T; i != S; i = From[i])
            tmp = min(tmp, Rest[Edge[i]]);
        for (int i = T; i != S; i = From[i])
        {
            Rest[Edge[i]] -= tmp;
            Rest[Edge[i] ^ 1] += tmp;
        }
        ans += tmp;
        return true;
    }
    for (int &i = cur[x], j; i; i = Next[i])
        if (Rest[i] > 0 && d[x] + 1 == d[j = Link[i]])
        {
            From[j] = x;
            Edge[j] = i;
            if (DFS(j))
                return true;
        }
    return false;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &S, &T);
    tot = 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &r);
        AddEdge(u, v, r);
        AddEdge(v, u, 0);
    }
    while (BFS())
    {
        memcpy(cur, Head, sizeof(cur));
        while (DFS(S));
    }
    printf("%d\n", ans);
    return 0;
}
