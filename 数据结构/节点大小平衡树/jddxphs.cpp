#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], f[N],  s[N], num[N], key[N];
inline void L(int p) {
    int t = r[p];
    if (r[p] = l[t])
        f[l[t]] = p;
    l[t] = p;
    if (f[t] = f[p])
        p == l[f[p]] ? l[f[p]] = t : r[f[p]] = t;
    f[p] = t;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + num[p];
    if (p == root)
        root = t;
}
inline void R(int p) {
    int t = l[p];
    if (l[p] = r[t])
        f[r[t]] = p;
    r[t] = p;
    if (f[t] = f[p])
        p == l[f[p]] ? l[f[p]] = t : r[f[p]] = t;
    f[p] = t;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + num[p];
    if (p == root)
        root = t;
}
void Fix(int p, bool flag) {
    if (flag)
        if (s[l[r[p]]] > s[l[p]])
            R(r[p]), L(p);
        else if (s[r[r[p]]] > s[l[p]])
            L(p);
        else
            return;
    else if (s[r[l[p]]] > s[r[p]])
        L(l[p]), R(p);
    else if (s[l[l[p]]] > s[r[p]])
        R(p);
    else
        return;
    Fix(l[p], 0);
    Fix(r[p], 1);
    Fix(p, 0);
    Fix(p, 1);
}
void Insert(int p, int q, int x) {
    if (!p) {
        p = ++pos;
        if (q)
            x < key[q] ? l[q] = p : r[q] = p;
        else
            root = p;
        key[p] = x;
        f[p] = q;
        s[p] = num[p] = 1;
    } else {
        s[p]++;
        if (x == key[p])
            num[p]++;
        else {
            Insert(x < key[p] ? l[p] : r[p], p, x);
            Fix(p, x > key[p]);
        }
    }
}
void Delete(int x) {
    int p, q, t;
    for (p = root; key[p] != x; p = x < key[p] ? l[p] : r[p])
        s[p]--;
    s[p]--;
    if (!(--num[p]))
        if (!l[p] || ! r[p]) {
            if (p == root)
                root = l[p] + r[p];
            else
                p == l[f[p]] ? l[f[p]] = l[p] + r[p] : r[f[p]] = l[p] + r[p];
            f[l[p] + r[p]] = f[p];
        } else {
            for (q = l[p]; r[q]; q = r[q]);
            for (t = l[p]; r[t]; t = r[t])
                s[t] -= num[q];
            q == l[f[q]] ? l[f[q]] = l[q] + r[q] : r[f[q]] = l[q] + r[q];
            f[l[q] + r[q]] = f[q];
            key[p] = key[q];
            num[p] = num[q];
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
    return 0;
}
