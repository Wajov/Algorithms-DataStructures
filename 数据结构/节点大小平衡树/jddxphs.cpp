#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], s[N], num[N], key[N];
inline void L(int &p) {
    int t = r[p];
    r[p] = l[t];
    l[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + num[p];
    p = t;
}
inline void R(int &p) {
    int t = l[p];
    l[p] = r[t];
    r[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + num[p];
    p = t;
}
void Fix(int &p, bool flag) {
    if (flag) {
        if (s[l[r[p]]] > s[l[p]])
            R(r[p]), L(p);
        else if (s[r[r[p]]] > s[l[p]])
            L(p);
        else
            return;
    } else {
        if (s[r[l[p]]] > s[r[p]])
            L(l[p]), R(p);
        else if (s[l[l[p]]] > s[r[p]])
            R(p);
        else
            return;
    }
    Fix(l[p], 0);
    Fix(r[p], 1);
    Fix(p, 0);
    Fix(p, 1);
}
void Insert(int &p, int x) {
    if (p) {
        s[p]++;
        if (x == key[p])
            num[p]++;
        else {
            Insert(x < key[p] ? l[p] : r[p], x);
            Fix(p, x > key[p]);
        }
    } else {
        p = ++pos;
        key[p] = x;
        s[p] = num[p] = 1;
    }
}
void Delete(int x) {
    int p, q, t, tmp;
    for (p = root, t = 0; x != key[p]; p = x < key[p] ? l[p] : r[p]) {
        s[p]--;
        t = p;
    }
    s[p]--;
    if (!(--num[p]))
        if (l[p]) {
            for (q = l[p], t = p; r[q]; q = r[q])
                t = q;
            for (tmp = l[p]; r[tmp]; tmp = r[tmp])
                s[tmp] -= num[q];
            key[p] = key[q];
            num[p] = num[q];
            q == l[t] ? l[t] = l[q] : r[t] = l[q];
        } else if (t)
            p == l[t] ? l[t] = r[p] : r[t] = r[p];
        else
            root = r[p];
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
