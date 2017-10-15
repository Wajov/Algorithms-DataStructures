#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double, double> Point;
const int N = 1000001;
int n;
double ans;
Point p[N];
inline double Cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 3; i <= n; i++)
        ans += Cross(p[1], p[i - 1], p[i]);
    printf("%f\n", ans / 2);
    return 0;
}
