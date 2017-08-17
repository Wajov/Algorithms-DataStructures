#include <bits/stdc++.h>
using namespace std;
int a, b, x, y, t;
int gcd(int a, int b, int &x, int &y)
{
    if (b)
    {
        int t, xt, yt;
        t = gcd(b, a % b, xt, yt);
        x = yt;
        y = xt - a / b * yt;
        return t;
    }
    else
    {
        x = 1;
        y = 0;
        return a;
    }
}
int main()
{
    scanf("%d%d", &a, &b);
    t = gcd(a, b, x, y);
    printf("%d %d %d\n", x, y, t);
    return 0;
}
