#include <bits/stdc++.h>
using namespace std;
int pos, son[1000001][26], num[1000001];
void Insert(char s[])
{
    int t = 1, tmp;
    for (int i = 0; s[i]; i++)
    {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            son[t][tmp] = ++pos;
        t = son[t][tmp];
    }
    num[t]++;
}
int Find(char s[])
{
    int t = 1, tmp;
    for (int i = 0; s[i]; i++)
    {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            return 0;
        t = son[t][tmp];
    }
    return num[t];
}
int main()
{
    pos = 1;
    return 0;
}
