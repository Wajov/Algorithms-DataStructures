#include <bits/stdc++.h>
using namespace std;
int n, sum[100001];
void Add(int x, int y)
{
    for (; x <= n; x += x & -x)
        sum[x] += y;
}
int Sum(int x)
{
    int ans = 0;
    for (; x; x -= x & -x)
        ans += sum[x];
    return ans;
}
int main()
{
    return 0;
}
