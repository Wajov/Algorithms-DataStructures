#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1000001, M = 1000001;
int n, m, u, v, tot, Head[N], Next[N << 1], Link[N << 1], a[N], ans[M];
bool flag[N];
vector<pair<int, int> > Q[N];
inline void AddEdge(int u, int v) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
int Get(int x) {
    if (a[x] != x)
        a[x] = Get(a[x]);
    return a[x];
}
void DFS(int x) {
    flag[x] = true;
    a[x] = x;
    for (int i = 0; i < Q[x].size(); i++)
        ans[Q[x][i].se] = Get(a[Q[x][i].fi]);
    for (int i = Head[x], j; i; i = Next[i])
        if (!flag[j = Link[i]]) {
            DFS(j);
            a[j] = x;
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        Q[u].push_back({v, i});
        Q[v].push_back({u, i});
    }
    DFS(1);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
