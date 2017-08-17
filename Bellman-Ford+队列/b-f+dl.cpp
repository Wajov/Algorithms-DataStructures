#include <bits/stdc++.h>
using namespace std;
int n, m, s, u, v, c, now, tot, Head[100001], Next[200001], Link[200001], Cost[200001], d[100001];
bool flag[100001];
queue<int> q;
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
    d[s] = 0;
    q.push(s);
    flag[s] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        flag[now] = false;
        for (int i = Head[now], j; i; i = Next[i])
            if (d[now] + Cost[i] < d[j = Link[i]])
            {
                d[j] = d[now] + Cost[i];
                if (!flag[j])
                {
                    q.push(j);
                    flag[j] = true;
                }
            }
    }
    for (int i = 1; i < n; i++)
        printf("%d ", d[i]);
    printf("%d\n", d[n]);
    return 0;
}
