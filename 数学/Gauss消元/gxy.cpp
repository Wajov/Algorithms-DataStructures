#include <bits/stdc++.h>
using namespace std;
const int N = 101, M = 101;
const double EPS = 1e-5;
int n, m, tmp;
double a[M][N + 1], t[M][N + 1], temp[N + 1];
bool flag;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n + 1; j++)
            scanf("%lf", &t[i][j]);
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        for (int j = 1; j <= m; j++) {
            flag = false;
            for (int k = 1; !flag && k <= n; k++)
                if (fabs(t[j][k]) > EPS)
                    flag = true;
            if (flag)
                memcpy(a[++tmp], t[j], sizeof(t[j]));
            else if (fabs(t[j][n + 1]) > EPS) {
                puts("No Solution");
                return 0;
            }
        }
        if ((m = tmp) < n) {
            puts("Infinite Solutions");
            return 0;
        }
        flag = false;
        for (int j = i; !flag && j <= m; j++)
            if (fabs(a[j][i]) > EPS) {
                memcpy(temp, a[i], sizeof(temp));
                memcpy(a[i], a[j], sizeof(temp));
                memcpy(a[j], temp, sizeof(temp));
                flag = true;
            }
        if (!flag) {
            puts("Infinite Solutions");
            return 0;
        }
        for (int j = i + 1; j <= n + 1; j++)
            a[i][j] /= a[i][i];
        a[i][i] = 1;
        for (int j = i + 1; j <= m; j++) {
            for (int k = i + 1; k <= n + 1; k++)
                a[j][k] -= a[i][k] * a[j][i];
            a[j][i] = 0;
        }
        memcpy(t, a, sizeof(a));
    }
    for (int i = n - 1; i; i--)
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
    for (int i = 1; i < n; i++)
        printf("%f ", a[i][n + 1]);
    printf("%f\n", a[n][n + 1]);
    return 0;
}
