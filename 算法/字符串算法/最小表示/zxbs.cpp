#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, x, y, t, ans;
char s[N + 10];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    x = 1;
    y = 2;
    for (int i = 0; x <= n && y <= n && i <= n; ) {
        t = s[(x + i - 1) % n + 1] - s[(y + i - 1) % n + 1];
        if (!t)
            i++;
        else {
            t > 0 ? x += i + 1 : y += i + 1;
            if (x == y)
                y++;
            i = 0;
        }
    }
    ans = min(x, y);
    for (int i = ans; i <= n; i++)
        putchar(s[i]);
    for (int i = 1; i < ans; i++)
        putchar(s[i]);
    puts("");
    return 0;
}
