#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], f[N], s[N], key[N];
inline void L(int p) {
    int t = f[p];
    if (r[t] = l[p])
        f[l[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    l[p] = t;
    s[p] = s[t];
    s[t] = s[l[t]] + s[r[t]] + 1;
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
    s[t] = s[l[t]] + s[r[t]] + 1;
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
void Insert(int &p, int q, int x) {
    if (p) {
        s[p]++;
        Insert(x < key[p] ? l[p] : r[p], p, x);
    } else {
        p = ++pos;
        f[p] = q;
        key[p] = x;
        s[p] = 1;
        Splay(p);
    }
}
int Delete(int &p, int q, int x) {
    int ans;
    s[p]--;
    if (x == key[p] || x < key[p] && !l[p] || x > key[p] && !r[p]) {
        ans = key[p];
        if (l[p])
            key[p] = Delete(l[p], p, x + 1);
        else {
            p = r[p];
            f[p] = q;
        }
    } else
        ans = Delete(x < key[p] ? l[p] : r[p], p, x);
    return ans;
}
int Rank(int x) {
    int p = root, t = s[l[root]], ans;
    while (p)
        if (x <= key[p]) {
            ans = t;
            p = l[p];
            t -= s[r[p]] + 1;
        } else {
            p = r[p];
            t += s[l[p]] + 1;
        }
    return ans + 1;
}
int Select(int x) {
    int p = root, t = s[l[root]];
    while (x != t + 1)
        if (x < t + 1) {
            p = l[p];
            t -= s[r[p]] + 1;
        } else {
            p = r[p];
            t += s[l[p]] + 1;
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
