#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], b[1000001];
int Find(int x)
{
    if (a[x] != x)
        a[x] = Find(a[x]);
    return a[x];
}
void Merge(int x, int y)
{
    if ((x = Find(x)) == (y = Find(y)))
        return;
    b[x] < b[y] ? a[x] = y : a[y] = x;
    if (b[x] == b[y])
        b[x]++;
}
int main()
{
    for (int i = 1; i <= n; i++)
        a[i] = i;
    return 0;
}
