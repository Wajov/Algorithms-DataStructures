#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 100001;
int n, m, x, y, ans, a[N];
pair<int, pair<int, int> > e[N];
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
		scanf("%d%d%d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
    for (int i = 1; i <= n; i++)
        a[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		x = Get(e[i].se.fi);
		y = Get(e[i].se.se);
		if (x != y)
		{
			a[x] = y;
			ans += e[i].fi;
		}
	}
	printf("%d\n", ans);
	return 0;
}
