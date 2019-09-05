#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, S, T, u, v, r, tot, Head[N], Next[M << 1], Link[M << 1], Rest[M << 1], h[N], s[N << 1], e[N];
bool flag[N];
queue<int> q;
priority_queue<pair<int, int> > pq;
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
    for (int i = Head[x], j; i; i = Next[i]) {
        j = Link[i];
        if (x == S || h[x] == h[j] + 1) {
            int t = min(e[x], Rest[i]);
            e[x] -= t;
            e[j] += t;
            Rest[i] -= t;
            Rest[i ^ 1] += t;
            if (j != S && j != T && !flag[j]) {
                pq.push(make_pair(h[j], j));
                flag[j] = true;
            }
        }
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
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        flag[now] = false;
        while (Push(now)) {
            if (!--s[h[now]])
                for (int i = 1; i <= n; i++)
                    if (i != S && i != T && h[i] > h[now] && h[i] <= n) {
                        s[h[i]]--;
                        s[h[i] = n + 1]++;
                    }
            Relabel(now);
            s[h[now]]++;
        }
    }
    printf("%d\n", e[T]);
    return 0;
}
