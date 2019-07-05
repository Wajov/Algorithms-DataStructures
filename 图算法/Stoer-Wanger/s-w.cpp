#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, m, u, v, c, tmp, ans, f[N], d[N];
bool flag[N];
vector<pair<int, int> > g[N];
int Get(int x) {
    if (f[x] != x)
        f[x] = Get(f[x]);
    return f[x];
}
int Cut(int nt) {
    memset(d, 0, sizeof(d));
    memset(flag, false, sizeof(flag));
    d[1] = INT_MAX;
    int ans;
    for (int i = 1; i <= nt; i++) {
        int tmp = INT_MIN, t;
        for (int j = 1; j <= n; j++)
            if (f[j] == j && !flag[j] && d[j] > tmp) {
                tmp = d[j];
                t = j;
            }
        flag[t] = true;
        for (int j = 0; j < g[t].size(); j++)
            d[Get(g[t][j].first)] += g[t][j].second;
        u = v;
        v = t;
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
