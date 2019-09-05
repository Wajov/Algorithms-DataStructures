#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, S, T, u, v, r, tot, Head[N], Next[M << 1], Link[M << 1], Rest[M << 1], h[N], s[N << 1], e[N];
bool flag;
queue<int> q;
inline void AddEdge(int u, int v, int r) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Rest[tot] = r;
    Head[u] = tot;
}
void BFS() {
    for (int i = 1; i <= n; i++)
        h[i] = INT_MAX;
    h[T] = 0;
    q.push(T);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = Head[now], j; i; i = Next[i])
            if (!Rest[i] && h[now] + 1 < h[j = Link[i]]) {
                h[j] = h[now] + 1;
                q.push(j);
            }
    }
}
bool Push(int x) {
    for (int i = Head[x]; i; i = Next[i])
        if (x == S || h[x] == h[Link[i]] + 1) {
            int t = min(e[x], Rest[i]);
            e[x] -= t;
            e[Link[i]] += t;
            Rest[i] -= t;
            Rest[i ^ 1] += t;
        }
    return e[x] > 0;
}
void Relabel(int x) {
    h[x] = INT_MAX;
    for (int i = Head[x]; i; i = Next[i])
        if (Rest[i])
            h[x] = min(h[x], h[Link[i]]);
    h[x]++;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &r);
        AddEdge(u, v, r);
        AddEdge(v, u, 0);
    }
    BFS();
    h[S] = n;
    for (int i = 1; i <= n; i++)
        s[h[i]]++;
    e[S] = INT_MAX;
    Push(S);
    flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i <= n; i++)
            if (i != S && i != T && e[i] > 0) {
                while (Push(i)) {
                    if (!--s[h[i]])
                        for (int j = 1; j <= n; j++)
                            if (j != S && j != T && h[j] > h[i] && h[j] <= n) {
                                s[h[j]]--;
                                s[h[j] = n + 1]++;
                            }
                    Relabel(i);
                    s[h[i]]++;
                }
                flag = true;
            }
    }
    printf("%d\n", e[T]);
    return 0;
}
