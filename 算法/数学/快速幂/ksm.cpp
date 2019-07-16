#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main() {
    scanf("%d%d", &a, &b);
    ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    printf("%d\n", ans);
    return 0;
}
