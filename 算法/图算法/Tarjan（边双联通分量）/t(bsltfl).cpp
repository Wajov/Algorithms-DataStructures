#include <bits/stdc++.h>
using namespace std;
const int N = 1000001, M = 1000001;
int n, m, u, v, tot, num, idx, Head[N], Next[M << 1], Link[M << 1], dfn[M << 1], low[N];
bool flag[N];
stack<int> s;
vector<int> sub[N];
inline void AddEdge(int u, int v) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Head[u] = tot;
}
void DFS(int x, int y) {
    s.push(x);
    flag[x] = true;
    low[x] = dfn[x] = ++idx;
    for (int i = Head[x], j; i; i = Next[i]) {
        if ((j = Link[i]) == y)
            continue;
        if (!dfn[j]) {
            DFS(j, x);
            low[x] = min(low[x], low[j]);
        } else if (flag[j])
            low[x] = min(low[x], dfn[j]);
    }
    if (low[x] > dfn[y]) {
        int t;
        num++;
        do {
            t = s.top();
            s.pop();
            flag[t] = false;
            sub[num].push_back(t);
        } while (t != x);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) {
            DFS(i, i);
            num++;
            while (!s.empty()) {
                flag[s.top()] = false;
                sub[num].push_back(s.top());
                s.pop();
            }
        }
    printf("%d\n", num);
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < sub[i].size() - 1; j++)
            printf("%d ", sub[i][j]);
        printf("%d\n", sub[i][sub[i].size() - 1]);
    }
    return 0;
}
