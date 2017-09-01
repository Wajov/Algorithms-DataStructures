#include <bits/stdc++.h>
using namespace std;
const int N = 100001, M = 100001;
int n, m, s, u, v, c, now, ans, tot, Head[N], Next[M << 1], Link[M << 1], Cost[M << 1], d[N];
bool flag[N];
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    q.push(make_pair(d[1] = 0, 1));
    while (!q.empty())
    {
        now = q.top().second;
        q.pop();
        if (flag[now])
            continue;
        ans += d[now];
        flag[now] = true;
        for (int i = Head[now], j; i; i = Next[i])
            if (Cost[i] < d[j = Link[i]])
            {
                d[j] = Cost[i];
                q.push(make_pair(-d[j], j));
            }
    }
    printf("%d\n", ans);
    return 0;
}
