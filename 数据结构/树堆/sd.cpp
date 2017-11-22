#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], f[N], s[N], num[N], wgt[N], key[N];
inline void L(int p) {
    int t = f[p];
    if (r[t] = l[p])
        f[l[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    l[p] = t;
    s[p] = s[t];
    s[t] = s[l[t]] + s[r[t]] + num[t];
    if (t == root)
        root = p;
}
inline void R(int p) {
    int t = f[p];
    if (l[t] = r[p])
        f[r[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    r[p] = t;
    s[p] = s[t];
    s[t] = s[l[t]] + s[r[t]] + num[t];
    if (t == root)
        root = p;
}
void Insert(int x) {
    int p, t;
    for (p = root; p && x != key[p]; p = x < key[p] ? l[p] : r[p]) {
        t = p;
        s[p]++;
    }
    if (p) {
        s[p]++;
        num[p]++;
    } else {
        p = ++pos;
        key[p] = x;
        wgt[p] = rand() % N + 1;
        s[p] = num[p] = 1;
        if (root) {
            f[p] = t;
            x < key[t] ? l[t] = p : r[t] = p;
            while (f[p] && wgt[p] > wgt[f[p]])
                p == l[f[p]] ? R(p) : L(p);
        } else
            root = p;
    }
}
void Delete(int x) {
    int p;
    for (p = root; x != key[p]; p = x < key[p] ? l[p] : r[p])
        s[p]--;
    s[p]--;
    if (!(--num[p])) {
        while (l[p] || r[p])
            wgt[l[p]] > wgt[r[p]] ? R(l[p]) : L(r[p]);
        if (f[p])
            p == l[f[p]] ? l[f[p]] = 0 : r[f[p]] = 0;
        else
            root = 0;
    }
}
int Rank(int x) {
    int p = root, t = s[l[root]];
    while (key[p] != x)
        if (x < key[p]) {
            p = l[p];
            t -= s[r[p]] + num[p];
        } else {
            t += num[p];
            p = r[p];
            t += s[l[p]];
        }
    return t + 1;
}
int Select(int x) {
    int p = root, t = s[l[root]];
    while (x < t + 1 || x > t + num[p])
        if (x < t + 1) {
            p = l[p];
            t -= s[r[p]] + num[p];
        } else {
            t += num[p];
            p = r[p];
            t += s[l[p]];
        }
    return key[p];
}
int Pred(int x) {
    int p = root, t;
    while (p)
        if (x > key[p]) {
            t = p;
            p = r[p];
        } else
            p = l[p];
    return key[t];
}
int Succ(int x) {
    int p = root, t;
    while (p)
        if (x < key[p]) {
            t = p;
            p = l[p];
        } else
            p = r[p];
    return key[t];
}
int main() {
    srand(time(NULL));
    return 0;
}
