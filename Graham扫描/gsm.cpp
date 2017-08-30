#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double, double> Point;
int n, top;
Point p[100001], s[100001];
inline double Cross(Point p0, Point p1, Point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
inline bool cmp(Point a, Point b)
{
    return Cross(p[0], a, b) > 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[i].y < p[0].y || p[i].y == p[0].y && p[i].x < p[0].x)
            swap(p[0], p[i]);
    }
    sort(p + 1, p + n, cmp);
    s[top = 1] = p[0];
    for (int i = 1; i < n; i++)
    {
        for (; top > 1 && Cross(s[top - 1], s[top], p[i]) < 0; top--);
        s[++top] = p[i];
    }
    printf("%d\n", top);
    for (int i = 1; i <= top; i++)
        printf("%.5f %.5f\n", s[i].x, s[i].y);
    return 0;
}
