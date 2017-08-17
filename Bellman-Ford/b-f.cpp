#include <bits/stdc++.h>
using namespace std;
int n, m, s, u, v, c, tot, Head[100001], Next[200001], Link[200001], Cost[200001], d[100001];
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
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[j] < INT_MAX)
                for (int k = Head[j]; k; k = Next[k])
                    d[Link[k]] = min(d[Link[k]], d[j] + Cost[k]);
    for (int i = 1; i < n; i++)
        printf("%d ", d[i]);
    printf("%d\n", d[n]);
    return 0;
}
