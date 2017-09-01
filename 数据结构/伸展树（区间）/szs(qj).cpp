#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int root, pos, l[N], r[N], f[N], s[N], key[N], lab[N], sum[N];
bool flag[N];
inline void Down(int p)
{
    if (l[p])
    {
        key[l[p]] += lab[p];
        lab[l[p]] += lab[p];
        sum[l[p]] += s[l[p]] * lab[p];
        if (flag[p])
        {
            flag[l[p]] = !flag[l[p]];
            swap(l[l[p]], r[l[p]]);
        }
    }
    if (r[p])
    {
        key[r[p]] += lab[p];
        lab[r[p]] += lab[p];
        sum[r[p]] += s[r[p]] * lab[p];
        if (flag[p])
        {
            flag[r[p]] = !flag[r[p]];
            swap(l[r[p]], r[r[p]]);
        }
    }
    lab[p] = 0;
    flag[p] = false;
}
inline void Up(int p)
{
    s[p] = s[l[p]] + s[r[p]] + 1;
    sum[p] = sum[l[p]] + sum[r[p]] + key[p];
}
inline void L(int p)
{
    int t = f[p];
    if (r[t] = l[p])
        f[l[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    l[p] = t;
}
inline void R(int p)
{
    int t = f[p];
    if (l[t] = r[p])
        f[r[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    r[p] = t;
}
void Splay(int p, int T)
{
    for (int q, t; (q = f[p]) != T; )
        if (f[q] == T)
        {
            p == l[q] ? R(p) : L(p);
            Up(q), Up(p);
        }
        else
        {
            t = f[q];
            if (p == l[q])
                q == l[t] ? (R(q), R(p)) : (R(p), L(p));
            else
                q == r[t] ? (L(q), L(p)) : (L(p), R(p));
            Up(t), Up(q), Up(p);
        }
    if (!T)
        root = p;
}
int Select(int x)
{
    int p = root, t = s[l[root]];
    Down(p);
    while (x != t + 1)
    {
        if (x < t + 1)
            t -= s[r[p = l[p]]] + 1;
        else
            t += s[l[p = r[p]]] + 1;
        Down(p);
    }
    return p;
}
void Insert(int x, int y)
{
    int p = Select(x + 1);
    Splay(p, 0);
    Down(p);
    for (p = r[p]; l[p]; p = l[p])
        Down(p);
    Down(p);
    l[p] = ++pos;
    f[pos] = p;
    sum[pos] = key[pos] = y;
    Splay(pos, 0);
}
void Delete(int x)
{
    int p = Select(x + 1);
    Splay(p, 0);
    Down(p);
    for (p = l[p]; r[p]; p = r[p])
        Down(p);
    Down(p);
    f[r[root]] = p;
    r[p] = r[root];
    f[l[root]] = 0;
    Splay(p, 0);
}
void Add(int x, int y, int z)
{
    Splay(Select(x), 0);
    Splay(Select(y + 2), root);
    key[l[r[root]]] += z;
    lab[l[r[root]]] += z;
    sum[l[r[root]]] += s[l[r[root]]] * z;
    Up(r[root]), Up(root);
}
void Reverse(int x, int y)
{
    Splay(Select(x), 0);
    Splay(Select(y + 2), root);
    flag[l[r[root]]] = !flag[l[r[root]]];
    swap(l[l[r[root]]], r[l[r[root]]]);
    Up(r[root]), Up(root);
}
int Sum(int x, int y)
{
    Splay(Select(x), 0);
    Splay(Select(y + 2), root);
    return sum[l[r[root]]];
}
int main()
{
    root = 1;
    pos = 2;
    r[1] = s[1] = 2;
    f[2] = s[2] = 1;
    return 0;
} 
