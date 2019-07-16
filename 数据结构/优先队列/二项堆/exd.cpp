#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int pos, d[N], f[N], key[N];
vector<int> son[N];
int Merge(int p, int q) {
    if (p == 0 || q == 0)
        return p | q;
    if (d[p] != d[q]) {
        if (d[p] > d[q])
            swap(p, q);
        f[p] = Merge(f[p], q);
    } else {
        if (key[p] < key[q])
            swap(p, q);
        son[p].push_back(q);
        d[p]++;
        q = Merge(f[p], f[q]);
        f[p] = 0;
        p = Merge(p, q);
    }
    return p;
}
void Push(int &p, int x) {
    key[++pos] = x;
    p = Merge(p, pos);
}
int Top(int p) {
    int ans = INT_MIN;
    for (; p; p = f[p])
        ans = max(ans, key[p]);
    return ans;
}
void Pop(int &p) {
    int q = p, t = 0, x = Top(p);
    for (; key[q] != x; q = f[q])
        t = q;
    if (!t)
        p = f[p];
    f[t] = f[f[t]];
    if (d[q]) {
        for (int i = 0; i < son[q].size() - 1; i++)
            f[son[q][i]] = son[q][i + 1];
        f[son[q][son[q].size() - 1]] = 0;
        p = Merge(p, son[q][0]);
    }
}
int main() {
    return 0;
}
