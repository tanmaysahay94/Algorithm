#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL m, n;
	cin >> m >> n;
	vector<VLL> b(m, VLL (n)), a(m, VLL(n, 1)), c(m, VLL(n));
	for (LL i = 0; i < m; i++)
		for (LL j = 0; j < n; j++)
		{
			SLL(b[i][j]);
			if (not b[i][j])
			{
				for (LL k = 0; k < n; k++)
					a[i][k] = 0;
				for (LL k = 0; k < m; k++)
					a[k][j] = 0;
			}
		}
	for (LL i = 0; i < m; i++)
		for (LL j = 0; j < n; j++)
		{
			LL val = 0;
			for (LL k = 0; k < n; k++)
				val |= a[i][k];
			for (LL k = 0; k < m; k++)
				val |= a[k][j];
			c[i][j] = val;
		}
	LL yes = 1;
	for (LL i = 0; i < m; i++)
	{
		for (LL j = 0; j < n; j++)
			if (b[i][j] != c[i][j])
			{
				yes = 0;
				break;
			}
		if (yes == 0)
			break;
	}
	if (yes)
	{
		printf("YES\n");
		for (LL i = 0; i < m; i++)
		{
			for (LL j = 0; j < n; j++)
				printf("%lld ", a[i][j]);
			printf("\n");
		}
	}
	else
		printf("NO\n");
	return 0;
}
