#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], s[N], key[N];
inline void L(int &p) {
    int t = r[p];
    r[p] = l[t];
    l[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + 1;
    p = t;
}
inline void R(int &p) {
    int t = l[p];
    l[p] = r[t];
    r[t] = p;
    s[t] = s[p];
    s[p] = s[l[p]] + s[r[p]] + 1;
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
    Fix(l[p], false);
    Fix(r[p], true);
    Fix(p, false);
    Fix(p, true);
}
void Insert(int &p, int x) {
    if (p) {
        s[p]++;
        Insert(x < key[p] ? l[p] : r[p], x);
        Fix(p, x >= key[p]);
    } else {
        p = ++pos;
        key[p] = x;
        s[p] = 1;
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
    Fix(p, false);
    Fix(p, true);
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
