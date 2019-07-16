#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, pos, last, son[N << 1][26], p[N << 1], val[N << 1], num[N << 1], sum[N], id[N << 1], rk[N << 1];
char s[N + 10];
void Insert(int x) {
    int u = last, ut = ++pos;
    val[ut] = val[u] + 1;
    num[ut] = 1;
    for (; u > 0 && !son[u][x]; u = p[u])
        son[u][x] = ut;
    if (!u)
        p[ut] = 1;
    else {
        int v = son[u][x], vt;
        if (val[v] == val[u] + 1)
            p[ut] = v;
        else {
            vt = ++pos;
            memcpy(son[vt], son[v], sizeof(son[v]));
            p[vt] = p[v];
            val[vt] = val[u] + 1;
            p[v] = p[ut] = vt;
            for (; u > 0 && son[u][x] == v; u = p[u])
                son[u][x] = vt;
        }
    }
    last = ut;
}
void Build() {
    n = strlen(s + 1);
    last = pos = 1;
    for (int i = 1; i <= n; i++)
        Insert(s[i] - 97);
    for (int i = 1; i <= pos; i++)
        sum[val[i]]++;
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    for (int i = pos; i; i--)
        rk[i] = sum[val[i]]--;
    for (int i = 1; i <= pos; i++)
        id[rk[i]] = i;
    for (int i = pos; i; i--)
        num[p[id[i]]] += num[id[i]];
}
int main() {
    return 0;
}
