#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n, key[100001], idx[100001], sum[100001], Rank[100010];
char s[100010];
pair<pair<int, int>, int> tmp[100001], temp[100001];
void Sort()
{
    for (int i = 1; i <= n; i++)
        key[i] = i;
    for (int i = 0; i < 2; i++)
    {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
            sum[tmp[i].x.y]++;
        for (int i = 1; i <= max(n, 130); i++)
            sum[i] += sum[i - 1];
        for (int i = 1; i <= n; i++)
            idx[key[i]] = i;
        for (int i = n; i; i--)
        {
            key[idx[i]] = sum[tmp[idx[i]].x.y]--;
            swap(tmp[idx[i]].x.x, tmp[idx[i]].x.y);
        }
    }
    for (int i = 1; i <= n; i++)
        temp[key[i]] = tmp[i];
    memcpy(tmp, temp, sizeof(tmp));
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        tmp[i] = {{s[i], s[i]}, i};
    Sort();
    for (int i = 1; i <= n; i <<= 1)
    {
        for (int j = 1, t = 0; j <= n; j++)
            Rank[tmp[j].y] = tmp[j].x == tmp[j - 1].x ? t : ++t;
        for (int j = 1; j <= n; j++)
            tmp[j] = {{Rank[j], Rank[min(i + j, n + 1)]}, j};
        Sort();
    }
    for (int i = 1; i < n; i++)
        printf("%d ", Rank[i]);
    printf("%d\n", Rank[n]);
    return 0;
}
