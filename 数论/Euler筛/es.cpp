#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, num, p[N], fai[N], miu[N];
bool flag[N];
int main()
{
    scanf("%d", &n);
    fai[1] = miu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!flag[i])
        {
            p[++num] = i;
            fai[i] = i - 1;
            miu[i] = -1;
        }
        for (int j = 1; j <= num; j++)
        {
            if (i * p[j] > n)
                break;
            flag[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                fai[i * p[j]] = fai[i] * p[j];
                miu[i * p[j]] = 0;
                break;
            }
            else
            {
                fai[i * p[j]] = fai[i] * (p[j] - 1);
                miu[i * p[j]] = -miu[i];
            }
        }
    }
    printf("%d\n", num);
    for (int i = 1; i < num; i++)
        printf("%d ", p[i]);
    printf("%d\n", p[num]);
    for (int i = 1; i < n; i++)
        printf("%d ", fai[i]);
    printf("%d\n", fai[n]);
    for (int i = 1; i < n; i++)
        printf("%d ", miu[i]);
    printf("%d\n", miu[n]);
    return 0;
}
