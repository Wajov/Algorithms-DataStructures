#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, ans, p[N << 1];
char c, s[N << 1];
int main() {
    s[0] = '$';
    while ((c = getchar()) != '\n') {
        s[++n] = '#';
        s[++n] = c;
    }
    s[++n] = '#';
    for (int i = 1, j = 0; i <= n; i++) {
        p[i] = i < j + p[j] ? min(p[(j << 1) - i], j + p[j] - i) : 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (i + p[i] > j + p[j])
            j = i;
        ans = max(ans, p[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}
