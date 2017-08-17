#include <bits/stdc++.h>
using namespace std;
int n, N, a[100001], sum[400001];
void Build()
{
    for (N = 1; N < n + 2; N <<= 1);
    for (int i = 1; i <= n; i++)
        sum[N + i] = a[i];
    for (int i = N - 1; i; i--)
        sum[i] = sum[i << 1] + sum[(i << 1) + 1];
}
void Add(int x, int y)
{
    for (x += N; x; x >>= 1)
        sum[x] += y;
}
int Sum(int x, int y)
{
    int ans = 0;
    for (x += N - 1, y += N + 1; x ^ y ^ 1; x >>= 1, y >>= 1)
    {
        if ((x & 1) == 0)
            ans += sum[x ^ 1];
        if ((y & 1) == 1)
            ans += sum[y ^ 1];
    }
    return ans;
}
int main()
{
    return 0;
}
