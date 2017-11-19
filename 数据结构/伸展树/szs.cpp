#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], f[N], key[N], s[N], num[N];
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
}
void Splay(int p) {
    for (int t; t = f[p]; )
        if (!f[t])
            p == l[t] ? R(p) : L(p);
        else if (p == l[t])
            t == l[f[t]] ? (R(t), R(p)) : (R(p), L(p));
        else
            t == r[f[t]] ? (L(t), L(p)) : (L(p), R(p));
    root = p;
}
void Insert(int x) {
    int p, t;
    for (p = root; p > 0 && x != key[p]; p = x < key[p] ? l[p] : r[p]) {
        t = p;
        s[p]++;
    }
    if (p) {
        s[p]++;
        num[p]++;
    } else {
        p = ++pos;
        key[p] = x;
        s[p] = num[p] = 1;
        if (root) {
            f[p] = t;
            x < key[t] ? l[t] = p : r[t] = p;
        }
    }
    Splay(p);
}
void Delete(int x) {
    int p;
    for (p = root; x != key[p]; p = x < key[p] ? l[p] : r[p]);
    Splay(p);
    if (!(--num[p]))
        if (l[p]) {
            for (p = l[p]; r[p]; p = r[p]);
            Splay(p);
            if (r[p] = r[r[p]])
                f[r[p]] = p;
        } else
            f[root = r[p]] = 0;
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
    Splay(p);
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
    Splay(p);
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
    Splay(t);
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
    Splay(t);
    return key[t];
}
int main() {
    return 0;
}
