#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int num, h[N];
bool Empty()
{
    return num > 0;
}
int Get()
{
    return h[1];
}
void Push(int x)
{
    h[++num] = x;
    for (int i = num; i > 1 && h[i] > h[i >> 1]; i >>= 1)
        swap(h[i], h[i >> 1]);
}
void Pop()
{
    swap(h[1], h[num--]);
    for (int i = 1, j; i << 1 <= num; i = j)
    {
        if ((i << 1) + 1 <= num && h[(i << 1) + 1] > h[i << 1])
            j = (i << 1) + 1;
        else
            j = i << 1;
        if (h[j] > h[i])
            swap(h[i], h[j]);
    }
}
int main()
{
    return 0;
}
