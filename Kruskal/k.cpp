#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n, m, x, y, ans, a[100001];
pair<int, pair<int, int> > e[100001];
int Get(int x)
{
	if (a[x] != x)
		a[x] = Get(a[x]);
	return a[x];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].y.x, &e[i].y.y, &e[i].x);
    for (int i = 1; i <= n; i++)
        a[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		x = Get(e[i].y.x);
		y = Get(e[i].y.y);
		if (x != y)
		{
			a[x] = y;
			ans += e[i].x;
		}
	}
	printf("%d\n", ans);
	return 0;
}
