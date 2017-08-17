#include <bits/stdc++.h>
using namespace std;
int top, s[10000001];
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
    top = 0;
    return 0;
}
