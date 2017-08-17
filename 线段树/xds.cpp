#include <bits/stdc++.h>
using namespace std;
int num, a[100001], l[400001], r[400001], lab[400001], sum[400001]; 
void Down(int p, int x, int y)
{
    int z = x + y >> 1;
    if (l[p])
    {
        lab[l[p]] += lab[p];
        sum[l[p]] += lab[p] * (z - x + 1);
    }
    if (r[p])
    {
        lab[r[p]] += lab[p];
        sum[r[p]] += lab[p] * (y - z);
    }
    lab[p] = 0;
}
void Build(int p, int x, int y)
{
    if (x == y)
    {
        sum[p] = a[x];
        return;
    }
    int z = x + y >> 1;
    Build(l[p] = ++num, x, z);
    Build(r[p] = ++num, z + 1, y);
    sum[p] = sum[l[p]] + sum[r[p]];
}
void Add(int p, int x, int y, int a, int b, int c)
{
    Down(p, x, y);
    if (x == a && y == b)
    {
        lab[p] = c;
        sum[p] += c * (b - a + 1);
        return;
    }
    int z = x + y >> 1;
    if (b <= z)
        Add(l[p], x, z, a, b, c);
    else if (a > z)
        Add(r[p], z + 1, y, a, b, c);
    else
    {
        Add(l[p], x, z, a, z, c);
        Add(r[p], z + 1, y, z + 1, b, c);
    }
    sum[p] = sum[l[p]] + sum[r[p]];
}
int Sum(int p, int x, int y, int a, int b)
{
    Down(p, x, y);
    if (x == a && y == b)
        return sum[p];
    int z = x + y >> 1;
    if (b <= z)
        return Sum(l[p], x, z, a, b);
    else if (a > z)
        return Sum(r[p], z + 1, y, a, b);
    else
        return Sum(l[p], x, z, a, z) + Sum(r[p], z + 1, y, z + 1, b);
}
int main()
{
    num = 1;
    return 0;
}
