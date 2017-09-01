#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int l, r, q[N << 1];
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
    l = N + 1;
    r = N;
    return 0;
}
