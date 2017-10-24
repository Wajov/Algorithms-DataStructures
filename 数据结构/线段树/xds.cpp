#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int num, a[N], l[N << 1], r[N << 1], ll[N << 1], rr[N << 1], sum[N << 1], lab[N << 1];
inline void Label(int p, int x) {
    sum[p] += (rr[p] - ll[p] + 1) * x;
    lab[p] += x;
}
inline void Down(int p) {
    if (ll[p] < rr[p]) {
        Label(l[p], lab[p]);
        Label(r[p], lab[p]);
    }
    lab[p] = 0;
}
inline void Up(int p) {
    sum[p] = sum[l[p]] + sum[r[p]];
}
void Build(int p, int x, int y) {
    ll[p] = x;
    rr[p] = y;
    if (x == y) {
        sum[p] = a[x];
        return;
    }
    int z = x + y >> 1;
    Build(l[p] = ++num, x, z);
    Build(r[p] = ++num, z + 1, y);
    Up(p);
}
void Add(int p, int x, int y, int z) {
    Down(p);
    if (ll[p] == x && rr[p] == y) {
        Label(p, z);
        return;
    }
    if (y < ll[r[p]])
        Add(l[p], x, y, z);
    else if (x > rr[l[p]])
        Add(r[p], x, y, z);
    else {
        Add(l[p], x, rr[l[p]], z);
        Add(r[p], ll[r[p]], y, z);
    }
    Up(p);
}
int Sum(int p, int x, int y) {
    Down(p);
    if (ll[p] == x && rr[p] == y)
        return sum[p];
    if (y < ll[r[p]])
        return Sum(l[p], x, y);
    else if (x > rr[l[p]])
        return Sum(r[p], x, y);
    else
        return Sum(l[p], x, rr[l[p]]) + Sum(r[p], ll[r[p]], y);
}
int main() {
    num = 1;
    return 0;
}
