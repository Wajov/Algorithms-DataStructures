#include <bits/stdc++.h>
using namespace std;
const int N = 1000001, M = 1000001;
int n, m, u, v, tot, num, idx, Head[N], Next[M], Link[M], dfn[N], low[N];
bool flag[N];
stack<int> s;
vector<int> sub[N];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS(int x)
{
    s.push(x);
    flag[x] = true;
    low[x] = dfn[x] = ++idx;
    for (int i = Head[x], j; i; i = Next[i])
        if (!dfn[j = Link[i]])
        {
            DFS(j);
            low[x] = min(low[x], low[j]);
        }
        else if (flag[j])
            low[x] = min(low[x], dfn[j]);
    if (low[x] == dfn[x])
    {
        int t;
        num++;
        do
        {
            t = s.top();
            s.pop();
            flag[t] = false;
            sub[num].push_back(t);
        }
        while (t != x);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            DFS(i);
    printf("%d\n", num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < sub[i].size() - 1; j++)
            printf("%d ", sub[i][j]);
        printf("%d\n", sub[i][sub[i].size() - 1]);
    }
    return 0;
}
