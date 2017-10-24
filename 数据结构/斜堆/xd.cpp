#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int l[N], r[N], key[N];
int Merge(int p, int q) {
    if (!p)
        return q;
    if (!q)
        return p;
    if (key[p] < key[q])
        swap(p, q);
    r[p] = Merge(r[p], q);
    swap(l[p], r[p]);
    return p;
}
int Top(int p) {
    return key[p];
}
void Pop(int &p) {
    p = Merge(l[p], r[p]);
}
int main() {
    return 0;
}
