#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, t, tmp, now, pos, ans, son[N][26], num[N], p[N];
char a[N + 10], b[N + 10];
queue<int> q;
void Insert(char s[]) {
    int t = 1, tmp;
    for (int i = 0; s[i]; i++) {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            son[t][tmp] = ++pos;
        t = son[t][tmp];
    }
    num[t]++;
}
int main() {
    pos = 1;
    scanf("%s%d", a, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", b);
        Insert(b);
    }
    q.push(1);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
            if (son[now][i]) {
                for (t = p[now]; t > 0 && son[t][i] == 0; t = p[t]);
                p[son[now][i]] = t ? son[t][i] : 1;
                q.push(son[now][i]);
            }
    }
    t = 1;
    for (int i = 0; a[i]; i++) {
        tmp = a[i] - 97;
        for (; t > 0 && son[t][tmp] == 0; t = p[t]);
        t = t ? son[t][tmp] : 1;
        for (int j = t; j > 1 && num[j] > -1; j = p[j]) {
            ans += num[j];
            num[j] = -1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
