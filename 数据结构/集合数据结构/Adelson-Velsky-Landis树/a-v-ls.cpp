#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], s[N], h[N], key[N];
inline void L(int &p) {
    int t = r[p];
    r[p] = l[t];
    l[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + 1;
    h[p] = max(h[l[p]], h[r[p]]) + 1;
    h[t] = max(h[l[t]], h[r[t]]) + 1;
    p = t;
}
inline void R(int &p) {
    int t = l[p];
    l[p] = r[t];
    r[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + 1;
    h[p] = max(h[l[p]], h[r[p]]) + 1;
    h[t] = max(h[l[t]], h[r[t]]) + 1;
    p = t;
}
void Fix(int &p) {
    if (h[l[p]] - h[r[p]] == 2)
        if (h[l[l[p]]] >= h[r[l[p]]])
            R(p);
        else
            L(l[p]), R(p);
    else if (h[l[p]] - h[r[p]] == -2)
        if (h[l[r[p]]] <= h[r[r[p]]])
            L(p);
        else
            R(r[p]), L(p);
}
void Insert(int &p, int x) {
    if (p) {
        s[p]++;
        Insert(x < key[p] ? l[p] : r[p], x);
        h[p] = max(h[l[p]], h[r[p]]) + 1;
        Fix(p);
    } else {
        p = ++pos;
        key[p] = x;
        s[p] = h[p] = 1;
    }
}
int Delete(int &p, int x) {
    int ans;
    s[p]--;
    if (x == key[p] || x < key[p] && !l[p] || x > key[p] && !r[p]) {
        ans = key[p];
        l[p] ? key[p] = Delete(l[p], x + 1) : p = r[p];
    } else
        ans = Delete(x < key[p] ? l[p] : r[p], x);
    if (p) {
        h[p] = max(h[l[p]], h[r[p]]) + 1;
        Fix(p);
    }
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
