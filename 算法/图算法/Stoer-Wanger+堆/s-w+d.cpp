#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, u, v, c, tmp, ans, f[N], d[N];
bool flag[N];
vector<pair<int, int> > g[N];
priority_queue<pair<int, int> > q;
int Get(int x) {
    if (f[x] != x)
        f[x] = Get(f[x]);
    return f[x];
}
int Cut(int nt) {
    memset(d, 0, sizeof(d));
    memset(flag, false, sizeof(flag));
    q.push(make_pair(d[1] = INT_MAX, 1));
    int ans;
    while (!q.empty()) {
        int tmp = q.top().first, now = q.top().second;
        q.pop();
        if (flag[now])
            continue;
        flag[now] = true;
        for (int i = 0, j; i < g[now].size(); i++) {
            j = Get(g[now][i].first);
            d[j] += g[now][i].second;
            q.push(make_pair(d[j], j));
        }
        u = v;
        v = now;
        ans = tmp;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i < n; i++) {
        tmp = Cut(n - i + 1);
        ans = min(ans, tmp);
        if (g[u].size() < g[v].size())
            swap(u, v);
        g[u].insert(g[u].end(), g[v].begin(), g[v].end());
        f[v] = u;
    }
    printf("%d\n", ans);
    return 0;
}
