#include <bits/stdc++.h>
using namespace std;
const int N = 1000001, M = 1000001;
int n, m, u, v, tot, num, Head[N], Next[M], Link[M], ans[N];
bool flag[N];
inline void AddEdge(int u, int v) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS(int x) {
    flag[x] = true;
    for (int i = Head[x], j; i; i = Next[i])
        if (!flag[j = Link[i]])
            DFS(j);
    ans[++num] = x;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!flag[i])
            DFS(i);
    for (int i = n; i > 1; i--)
        printf("%d ", ans[i]);
    printf("%d\n", ans[1]);
    return 0;
}
