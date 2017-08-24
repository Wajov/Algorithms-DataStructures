#include <bits/stdc++.h>
using namespace std;
int n, m, num, p[1000001], ans[1000001];
char a[1000010], b[1000010];
int main()
{
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        for (; j > 0 && b[j + 1] != b[i]; j = p[j]);
        if (b[j + 1] == b[i])
            j++;
        p[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        for (; j > 0 && b[j + 1] != a[i]; j = p[j]);
        if (b[j + 1] == a[i])
            j++;
        if (j == m)
        {
            ans[++num] = i - j + 1;
            j = p[j];
        }
    }
    for (int i = 1; i < num; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[num]);
    return 0;
}
