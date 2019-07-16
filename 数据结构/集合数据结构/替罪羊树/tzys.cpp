#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, num, l[N], r[N], s[N], key[N], tmp[N];
void Get(int p) {
    if (!p)
        return;
    Get(l[p]);
    tmp[++num] = p;
    Get(r[p]);
}
int Put(int x, int y) {
    if (x > y)
        return 0;
    int z = x + y >> 1, p = tmp[z];
    l[p] = Put(x, z - 1);
    r[p] = Put(z + 1, y);
    s[p] = s[l[p]] + s[r[p]] + 1;
    return p;
}
void Fix(int &p) {
    if (s[l[p]] < s[p] >> 2 || s[r[p]] < s[p] >> 2) {
        num = 0;
        Get(p);
        p = Put(1, num);
    }
}
void Insert(int &p, int x) {
    if (p) {
        Fix(p);
        s[p]++;
        Insert(x < key[p] ? l[p] : r[p], x);
    } else {
        p = ++pos;
        key[p] = x;
        s[p] = 1;
    }
}
int Delete(int &p, int x) {
    int ans;
    Fix(p);
    s[p]--;
    if (x == key[p] || x < key[p] && !l[p] || x > key[p] && !r[p]) {
        ans = key[p];
        l[p] ? key[p] = Delete(l[p], x + 1) : p = r[p];
    } else
        ans = Delete(x < key[p] ? l[p] : r[p], x);
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
