#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int a, b, ans;
int main()
{
    scanf("%d%d", &a, &b);
    ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (long long)ans * (long long)a % MOD;
        a = (long long)a * (long long)a % MOD;
        b >>= 1;
    }
    printf("%d\n", ans);
    return 0;
}
