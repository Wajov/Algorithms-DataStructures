#include <bits/stdc++.h>
using namespace std;
int n, ans, p[2000001];
char c, s[2000010];
int main()
{
    s[0] = '$';
    while ((c = getchar()) != '\n')
    {
        s[++n] = '#';
        s[++n] = c;
    }
    s[++n] = '#';
    for (int i = 1, j = 0; i <= n; i++)
    {
        for (p[i] = i < j + p[j] ? min(p[(j << 1) - i], j + p[j] - i) : 1; s[i + p[i]] == s[i - p[i]]; p[i]++);
        if (i + p[i] > j + p[j])
            j = i;
        ans = max(ans, p[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}
