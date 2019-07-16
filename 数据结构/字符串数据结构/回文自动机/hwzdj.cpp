#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, pos, last, son[N][26], p[N], len[N], num[N];
char s[N + 10];
int Get(int x, int n) {
    for (; s[n - len[x] - 1] != s[n]; x = p[x]);
    return x;
}
void Insert(int x, int n) {
    int t = Get(last, n);
    if (!son[t][x]) {
        p[++pos] = son[Get(p[t], n)][x];
        len[pos] = len[t] + 2;
        son[t][x] = pos;
    }
    num[last = son[t][x]]++;
}
void Build() {
    n = strlen(s + 1);
    p[0] = pos = 1;
    len[1] = -1;
    for (int i = 1; i <= n; i++)
        Insert(s[i] - 97, i);
    for (int i = pos; i >= 0; i--)
        num[p[i]] += num[i];
}
int main() {
    return 0;
}
