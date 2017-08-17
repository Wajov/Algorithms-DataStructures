#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, tot, num, idx, Head[1000001], Next[2000001], Link[2000001], dfn[1000001], low[1000001];
bool flag[1000001];
stack<int> s;
vector<int> sub[1000001];
inline void AddEdge(int u, int v)
{
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS(int x, int y)
{
    s.push(x);
    flag[x] = true;
    low[x] = dfn[x] = ++idx;
    for (int i = Head[x], j; i; i = Next[i])
    {
        if ((j = Link[i]) == y)
            continue;
        if (!dfn[j])
        {
            DFS(j, x);
            low[x] = min(low[x], low[j]);
        }
        else if (flag[j])
            low[x] = min(low[x], dfn[j]);
    }
    if (low[x] > dfn[y])
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
        AddEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            DFS(i, i);
            num++;
            while (!s.empty())
            {
                flag[s.top()] = false;
                sub[num].push_back(s.top());
                s.pop();
            }
        }
    printf("%d\n", num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < sub[i].size() - 1; j++)
            printf("%d ", sub[i][j]);
        printf("%d\n", sub[i][sub[i].size() - 1]);
    }
    return 0;
}
