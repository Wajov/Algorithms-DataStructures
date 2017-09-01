#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int top, s[N];
bool Empty()
{
    return top == 0;
}
int Get()
{
    return s[top];
}
void Push(int x)
{
    s[++top] = x;
}
void Pop()
{
    top--;
}
int main()
{
    return 0;
}
