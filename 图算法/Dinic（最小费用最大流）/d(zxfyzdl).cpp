#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, S, T, u, v, r, c, tot, ans1, ans2, Head[N], cur[N], Next[M << 1], Link[M << 1], Rest[M << 1], Cost[M << 1], d[N], From[N], Edge[N];
bool flag[N];
queue<int> q;
inline void AddEdge(int u, int v, int r, int c) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Rest[tot] = r;
    Cost[tot] = c;
    Head[u] = tot;
}
bool BFS() {
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    d[S] = 0;
    q.push(S);
    flag[S] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        flag[now] = false;
        for (int i = Head[now], j; i; i = Next[i])
            if (Rest[i] > 0 && d[now] + Cost[i] < d[j = Link[i]]) {
                d[j] = d[now] + Cost[i];
                if (!flag[j]) {
                    q.push(j);
                    flag[j] = true;
                }
            }
    }
    return d[T] < INT_MAX;
}
bool DFS(int x) {
    if (x == T) {
        int tmp = INT_MAX, sum = 0;
        for (int i = T; i != S; i = From[i]) {
            tmp = min(tmp, Rest[Edge[i]]);
            sum += Cost[Edge[i]];
        }
        for (int i = T; i != S; i = From[i]) {
            Rest[Edge[i]] -= tmp;
            Rest[Edge[i] ^ 1] += tmp;
        }
        ans1 += tmp;
        ans2 += tmp * sum;
        return true;
    }
    flag[x] = true;
    for (int &i = cur[x], j; i; i = Next[i]) {
        j = Link[i];
        if (Rest[i] > 0 && !flag[j] && d[x] + Cost[i] == d[j]) {
            From[j] = x;
            Edge[j] = i;
            if (DFS(j)) {
                flag[x] = false;
                return true;
            }
        }
    }
    flag[x] = false;
    return false;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &u, &v, &r, &c);
        AddEdge(u, v, r, c);
        AddEdge(v, u, 0, -c);
    }
    while (BFS()) {
        memcpy(cur, Head, sizeof(cur));
        while (DFS(S));
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
