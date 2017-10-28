#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int num, l[N], r[N], key[N];
int Merge(int p, int q) {
    if (!p)
        return q;
    if (!q)
        return p;
    if (key[p] > key[q])
        swap(p, q);
    r[p] = Merge(r[p], q);
    swap(l[p], r[p]);
    return p;
}
void Push(int &p, int x) {
    key[++num] = x;
    p = Merge(p, num);
}
void Pop(int &p) {
    p = Merge(l[p], r[p]);
}
int Top(int p) {
    return key[p];
}
int main() {
    return 0;
}
