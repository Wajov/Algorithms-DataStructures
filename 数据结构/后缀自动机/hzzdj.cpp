#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, pos, last, son[N << 1][26], par[N << 1], val[N << 1], sum[N], id[N << 1], rk[N << 1], sz[N << 1];
char s[N + 10];
void Insert(int x) {
    int p = last, np = ++pos;
    val[np] = val[p] + 1;
    sz[np] = 1;
    for (; p > 0 && !son[p][x]; p = par[p])
        son[p][x] = np;
    if (!p)
        par[np] = 1;
    else {
        int q = son[p][x], nq;
        if (val[q] == val[p] + 1)
            par[np] = q;
        else {
            nq = ++pos;
            memcpy(son[nq], son[q], sizeof(son[q]));
            par[nq] = par[q];
            val[nq] = val[p] + 1;
            par[q] = par[np] = nq;
            for (; p > 0 && son[p][x] == q; p = par[p])
                son[p][x] = nq;
        }
    }
    last = np;
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
        sz[par[id[i]]] += sz[id[i]];
}
int main() {
    return 0;
}
