#include <bits/stdc++.h>
using namespace std;
int root, pos, l[100001], r[100001], f[100001], key[100001], s[100001], num[100001];
inline void L(int p)
{
    int t = f[p];
    if (r[t] = l[p])
        f[l[p]] = t;
    if (f[p] = f[t])
        t == l[f[t]] ? l[f[t]] = p : r[f[t]] = p;
    f[t] = p;
    l[p] = t;
    s[p] = s[t];
    s[t] = s[l[t]] + s[r[t]] + num[t];
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
    s[p] = s[t];
    s[t] = s[l[t]] + s[r[t]] + num[t];
}
void Splay(int p)
{
    for (int t; t = f[p]; )
        if (!f[t])
            p == l[t] ? R(p) : L(p);
        else
            if (p == l[t])
                t == l[f[t]] ? (R(t), R(p)) : (R(p), L(p));
            else
                t == r[f[t]] ? (L(t), L(p)) : (L(p), R(p));
    root = p;
}
void Insert(int x)
{
    int p, t;
    bool flag = false;
    for (p = root; p; p = x < key[p] ? l[p] : r[p])
    {
        t = p;
        s[p]++;
        if (key[p] == x)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        num[p]++;
    else
    {
        p = ++pos;
        key[p] = x;
        s[p] = num[p] = 1;
        if (root)
        {
            f[p] = t;
            x < key[t] ? l[t] = p : r[t] = p;
        }
    }
    Splay(p);
}
void Delete(int x)
{
    int p, q, t;
    for (p = root; key[p] != x; p = x < key[p] ? l[p] : r[p])
        s[p]--;
    s[p]--;
    if (!(--num[p]))
        if (!l[p] || ! r[p])
        {
            if (p == root)
                root = l[p] + r[p];
            else
                p == l[f[p]] ? l[f[p]] = l[p] + r[p] : r[f[p]] = l[p] + r[p];
            f[l[p] + r[p]] = f[p];
        }
        else
        {
            for (q = l[p]; r[q]; q = r[q]);
            for (t = l[p]; r[t]; t = r[t])
                s[t] -= num[q];
            q == l[f[q]] ? l[f[q]] = l[q] + r[q] : r[f[q]] = l[q] + r[q];
            f[l[q] + r[q]] = f[q];
            key[p] = key[q];
            num[p] = num[q];
        }
}
int Rank(int x)
{
    int p = root, t = s[l[root]];
    while (key[p] != x)
        if (x < key[p])
        {
            p = l[p];
            t -= s[r[p]] + num[p];
        }
        else
        {
            t += num[p];
            p = r[p];
            t += s[l[p]];
        }
    Splay(p);
    return t + 1;
}
int Select(int x)
{
    int p = root, t = s[l[root]];
    while (x < t + 1 || x > t + num[p])
        if (x < t + 1)
        {
            p = l[p];
            t -= s[r[p]] + num[p];
        }
        else
        {
            t += num[p];
            p = r[p];
            t += s[l[p]];
        }
    Splay(p);
    return key[p];
}
int Pred(int x)
{
    int p = root, t;
    while (p)
        if (x > key[p])
        {
            t = p;
            p = r[p];
        }
        else
            p = l[p];
    Splay(t);
    return key[t];
}
int Succ(int x)
{
    int p = root, t;
    while (p)
        if (x < key[p])
        {
            t = p;
            p = l[p];
        }
        else
            p = r[p];
    Splay(t);
    return key[t];
}
int main()
{
    return 0;
}
