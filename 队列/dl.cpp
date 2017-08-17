#include <bits/stdc++.h>
using namespace std;
int l, r, q[10000001];
bool Empty()
{
    return l > r;
}
int Get()
{
    return q[l];
}
void Push(int x)
{
    q[++r] = x;
}
void Pop()
{
    l++;
}
int main()
{
    l = 1;
    r = 0;
    return 0;
}
