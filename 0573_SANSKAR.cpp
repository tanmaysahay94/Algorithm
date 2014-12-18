#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int t;
	si(t);
	while (t--)
	{
		LL n, k, val;
		LL sum = 0;
		sll(n);
		sll(k);
		VLL a;
		for (LL i = 0; i < n; i++)
		{
			sll(val);
			sum += val;
			if (val)
				a.pb(val);
		}
		if (k > n)
		{
			printf("no\n");
			continue;
		}
		if (sum == 0)
		{
			printf("yes\n");
			continue;
		}
		if (sum % k)
		{
			printf("no\n");
			continue;
		}
		sort(a.rbegin(), a.rend());
		if (sum/k < a[0])
		{
			printf("no\n");
			continue;
		}
		n = a.size();
		sum /= k;
		LL lim = 1LL << n;
		LL pcount = 0;
		vector<bool> visited(n, false);
		for (LL i = 0; i < lim; i++)
		{
			LL j = i;
			LL bit = 0;
			LL cur = 0;
			while (j)
			{
				if (j & 1 and not visited[bit])
					cur += a[bit];
				bit++;
				j >>= 1;
			}
			j = i;
			bit = 0;
			if (cur == sum)
			{
				pcount++;
				while (j)
				{
					if (j & 1)
						visited[bit] = true;
					bit++;
					j >>= 1;
				}
			}
		}
		bool all = true;
		for (LL i = 0; i < n; i++)
			all &= visited[i];
		if (all and pcount == k)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
