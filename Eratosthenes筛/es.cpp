#include <bits/stdc++.h>
using namespace std;
int n, num, p[1000001];
bool flag[1000001];
int main()
{
    scanf("%d", &n);
    memset(flag, true, sizeof(flag));
    for (int i = 2; i <= n >> 1; i++)
        if (flag[i])
        {
            p[++num] = i;
            for (int j = i << 1; j <= n; j += i)
                flag[j] = false;
        }
    for (int i = 1; i < num; i++)
        printf("%d ", p[i]);
    printf("%d\n", p[num]);
    return 0;
}
