#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int l[N], r[N], d[N], key[N];
int Merge(int p, int q) {
    if (!p)
        return q;
    if (!q)
        return p;
    if (key[p] < key[q])
        swap(p, q);
    r[p] = Merge(r[p], q);
    if (d[l[p]] < d[r[p]])
        swap(l[p], r[p]);
    d[p] = d[r[p]] + 1;
    return p;
}
int Top(int p) {
    return key[p];
}
void Pop(int &p) {
    p = Merge(l[p], r[p]);
}
int main() {
    d[0] = -1;
    return 0;
}
