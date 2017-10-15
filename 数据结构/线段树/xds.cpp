#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int num, a[N], l[N << 1], r[N << 1], sum[N << 1], lab[N << 1];
inline void Label(int p, int x, int y, int z) {
    sum[p] += (y - x + 1) * z;
    lab[p] += z;
}
inline void Down(int p, int x, int y) {
    if (x < y) {
        int z = x + y >> 1;
        Label(l[p], x, z, lab[p]);
        Label(r[p], z + 1, y, lab[p]);
    }
    lab[p] = 0;
}
inline void Up(int p) {
    sum[p] = sum[l[p]] + sum[r[p]];
}
void Build(int p, int x, int y) {
    if (x == y) {
        sum[p] = a[x];
        return;
    }
    int z = x + y >> 1;
    Build(l[p] = ++num, x, z);
    Build(r[p] = ++num, z + 1, y);
    Up(p);
}
void Add(int p, int x, int y, int a, int b, int c) {
    Down(p, x, y);
    if (x == a && y == b) {
        Label(p, x, y, c);
        return;
    }
    int z = x + y >> 1;
    if (b <= z)
        Add(l[p], x, z, a, b, c);
    else if (a > z)
        Add(r[p], z + 1, y, a, b, c);
    else {
        Add(l[p], x, z, a, z, c);
        Add(r[p], z + 1, y, z + 1, b, c);
    }
    Up(p);
}
int Sum(int p, int x, int y, int a, int b) {
    Down(p, x, y);
    if (x == a && y == b)
        return sum[p];
    int z = x + y >> 1;
    if (b <= z)
        return Sum(l[p], x, z, a, b);
    else if (a > z)
        return Sum(r[p], z + 1, y, a, b);
    else
        return Sum(l[p], x, z, a, z) + Sum(r[p], z + 1, y, z + 1, b);
}
int main() {
    num = 1;
    return 0;
}
