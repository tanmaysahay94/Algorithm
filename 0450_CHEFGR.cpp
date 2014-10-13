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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t, n, m;
	SLL(t);
	while (t--)
	{
		SLL(n); SLL(m);
		VLL v(n);
		for (int i = 0; i < n; i++)
			SLL(v[i]);
		sortv(v);
		LL req = 0;
		for (int i = 0; i < n - 1; i++)
			req += v[n - 1] - v[i];
		if (req > m)
			printf("No\n");
		else
		{
			if ((m - req) % n == 0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
