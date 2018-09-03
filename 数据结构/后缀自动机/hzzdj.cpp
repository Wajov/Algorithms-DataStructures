#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int pos, last, son[N << 1][26], par[N << 1], val[N << 1];
void Insert(int x) {
    int p = last, np = ++pos;
    val[np] = val[p] + 1;
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
int main() {
    last = pos = 1;
    return 0;
}
