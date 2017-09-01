#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, S, T, u, v, r, tot, tmp, ans, Head[N], Next[M << 1], Link[M << 1], Rest[M << 1], From[N], Edge[N];
bool flag[N];
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
    memset(flag, false, sizeof(flag));
    flag[S] = true;
    q.push(S);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = Head[now], j; i; i = Next[i])
            if (Rest[i] > 0 && !flag[j = Link[i]])
            {
                flag[j] = true;
                From[j] = now;
                Edge[j] = i;
                q.push(j);
            }
    }
    return flag[T];
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
        tmp = INT_MAX;
        for (int i = T; i != S; i = From[i])
            tmp = min(tmp, Rest[Edge[i]]);
        for (int i = T; i != S; i = From[i])
        {
            Rest[Edge[i]] -= tmp;
            Rest[Edge[i] ^ 1] += tmp;
        }
        ans += tmp;
    }
    printf("%d\n", ans);
    return 0;
}
