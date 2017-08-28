#include <bits/stdc++.h>
using namespace std;
int n, m, s, u, v, c, now, tot, d[100001], Head[100001], Next[200001], Link[200001], Cost[200001];
bool flag[100001];
priority_queue<pair<int, int> > q;
inline void AddEdge(int u, int v, int c)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Cost[tot] = c;
    Head[u] = tot;
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    q.push(make_pair(d[s] = 0, s));
    while (!q.empty())
    {
        now = q.top().second;
        q.pop();
        if (flag[now])
            continue;
        flag[now] = true;
        for (int i = Head[now], j; i; i = Next[i])
            if (d[now] + Cost[i] < d[j = Link[i]])
            {
                d[j] = d[now] + Cost[i];
                q.push(make_pair(-d[j], j));
            }
    }
    for (int i = 1; i < n; i++)
        printf("%d ", d[i] == INT_MAX ? -1 : d[i]);
    printf("%d\n", d[n] == INT_MAX ? -1 : d[n]);
    return 0;
}
