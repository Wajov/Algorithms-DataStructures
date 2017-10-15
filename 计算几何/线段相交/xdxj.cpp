#include <bits/stdc++.h>
#define x first
#define y second
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
using namespace std;
typedef pair<double, double> Point;
typedef pair<Point, Point> Segment;
Segment a, b;
inline double Cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int main() {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.x1, &a.y1, &a.x2, &a.y2, &b.x1, &b.y1, &b.x2, &b.y2);
    if (max(a.x1, a.x2) < min(b.x1, b.x2) || max(b.x1, b.x2) < min(a.x1, a.x2))
        puts("NO");
    else if (max(a.y1, a.y2) < min(b.y1, b.y2) || max(b.y1, b.y2) < min(a.y1, a.y2))
        puts("NO");
    else
        puts(Cross(a.x, a.y, b.x) * Cross(a.x, a.y, b.y) <= 0 && Cross(b.x, b.y, a.x) * Cross(b.x, b.y, a.y) <= 0 ? "YES" : "NO");
    return 0;
}
