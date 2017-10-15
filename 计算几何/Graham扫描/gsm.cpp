#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double, double> Point;
const int N = 100001;
int n, top;
Point p[N], s[N];
inline double Sqr(double x) {
	return x * x;
}
inline double Dist(Point a, Point b) {
	return sqrt(Sqr(a.x - b.x) + Sqr(a.y - b.y));
}
inline double Cross(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
inline bool cmp(Point a, Point b) {
	return Cross(p[0], a, b) > 0 || Cross(p[0], a, b) == 0 && Dist(p[0], a) < Dist(p[0], b);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (p[i].y < p[0].y || p[i].y == p[0].y && p[i].x < p[0].x)
			swap(p[0], p[i]);
	}
	sort(p + 1, p + n, cmp);
	s[top = 1] = p[0];
	for (int i = 1; i < n; i++) {
		for (; top > 1 && Cross(s[top - 1], s[top], p[i]) < 0; top--);
		s[++top] = p[i];
	}
	for (; top > 2 && Cross(s[top - 1], s[top], s[1]) < 0; top--);
	printf("%d\n", top);
	for (int i = 1; i <= top; i++)
		printf("%f %f\n", s[i].x, s[i].y);
	return 0;
}
