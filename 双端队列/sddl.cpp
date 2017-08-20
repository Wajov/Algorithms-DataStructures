#include <bits/stdc++.h>
using namespace std;
int l, r, q[10000001];
bool Empty()
{
    return l > r;
}
int GetFront()
{
    return q[l];
}
int GetBack()
{
    return q[r];
}
void PushFront(int x)
{
    q[--l] = x;
}
void PushBack(int x)
{
    q[++r] = x;
}
void PopFront()
{
    l++;
}
void PopBack()
{
    r--;
}
int main()
{
    l = 5000001;
    r = 5000000;
    return 0;
}
