#include <bits/stdc++.h>
using namespace std;
int n, t, ans, p[1000001];
char c, s[1000001];
int main()
{
    s[0] = '$';
    while ((c = getchar()) != '\n')
    {
        s[++n] = '#';
        s[++n] = c;
    }
    s[++n] = '#';
    for (int i = 1; i <= n; i++)
    {
        for (p[i] = t + p[t] > i ? min(p[t * 2 - i], t + p[t] - i) : 1; s[i + p[i]] == s[i - p[i]]; p[i]++);
        if (i + p[i] > t + p[t])
            t = i;
        ans = max(ans, p[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}
