#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll Mul(ll a, ll b, ll MOD) {
    ll ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % MOD;
        a = (a << 1) % MOD;
        b >>= 1;
    }
    return ans;
}
ll Pow(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = Mul(ans, a, MOD);
        a = Mul(a, a, MOD);
        b >>= 1;
    }
    return ans;
}
bool Judge(ll p) {
    if (p < 2)
        return false;
    int num = 0;
    ll t = p - 1, t1, t2;
    for (; !(t & 1); t >>= 1)
        num++;
    for (int i = 0; i < 5; i++) {
        t1 = Pow(rand() % (p - 1) + 1, t, p);
        for (int j = 0; t1 != 1 && j < num; j++) {
            t2 = Mul(t1, t1, p);
            if (t1 != 1 && t1 != p - 1 && t2 == 1)
                return false;
            t1 = t2;
        }
        if (t1 != 1)
            return false;
    }
    return true;
}
int main() {
    srand(time(NULL));
    scanf("%lld", &n);
    puts(Judge(n) ? "YES" : "NO");
    return 0;
}
