#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int l, r, q[N];
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
    return 0;
}
