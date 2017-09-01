#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, SIZE, a[N], sum[N << 2];
void Build()
{
    for (SIZE = 1; SIZE < n + 2; SIZE <<= 1);
    for (int i = 1; i <= n; i++)
        sum[SIZE + i] = a[i];
    for (int i = SIZE - 1; i; i--)
        sum[i] = sum[i << 1] + sum[(i << 1) + 1];
}
void Add(int x, int y)
{
    for (x += SIZE; x; x >>= 1)
        sum[x] += y;
}
int Sum(int x, int y)
{
    int ans = 0;
    for (x += SIZE - 1, y += SIZE + 1; x ^ y ^ 1; x >>= 1, y >>= 1)
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
