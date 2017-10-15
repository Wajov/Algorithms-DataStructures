#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, sum[N];
void Add(int x, int y) {
    for (; x <= n; x += x & -x)
        sum[x] += y;
}
int Sum(int x) {
    int ans = 0;
    for (; x; x -= x & -x)
        ans += sum[x];
    return ans;
}
int main() {
    return 0;
}
