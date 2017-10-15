#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double, double> Point;
const int N = 1000001;
int x, y, n;
double r;
Point O, p[N];
inline double Sqr(double x) {
    return x * x;
}
inline double Dist(Point a, Point b) {
    return sqrt(Sqr(a.x - b.x) + Sqr(a.y - b.y));
}
inline Point Calc(Point a, Point b, Point c) {
    if (fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) < 1e-5)
        if (Dist(a, c) > Dist(b, c))
            return {(a.x + c.x) / 2, (a.y + c.y) / 2};
        else
            return {(b.x + c.x) / 2, (b.y + c.y) / 2};
    double k1, k2, b1, b2;
    k1 = (a.x - c.x) / (c.y - a.y);
    b1 = (a.y + c.y) / 2 - k1 * (a.x + c.x) / 2;
    k2 = (b.x - c.x) / (c.y - b.y);
    b2 = (b.y + c.y) / 2 - k2 * (b.x + c.x) / 2;
    return {(b2 - b1) / (k1 - k2), (k1 * b2 - k2 * b1) / (k1 - k2)};
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    random_shuffle(p + 1, p + n + 1);
    O = p[1];
    r = 0;
    for (int i = 2; i <= n; i++)
        if (Dist(O, p[i]) > r) {
            O = p[i];
            r = 0;
            for (int j = 1; j < i; j++)
                if (Dist(O, p[j]) > r) {
                    O = {(p[i].x + p[j].x) / 2, (p[i].y + p[j].y) / 2};
                    r = Dist(O, p[j]);
                    for (int k = 1; k < j; k++)
                        if (Dist(O, p[k]) > r) {
                            O = Calc(p[i], p[j], p[k]);
                            r = Dist(O, p[k]);
                        }
                }
        }
    printf("%f %f\n%f\n", O.x, O.y, r);
    return 0;
}
