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
	int n;
	ULL a, b;
	si(n);
	while (n--)
	{
		sull(a); sull(b);
		int count = 0;
		while (a != b)
		{
			if (a > b)
				a >>= 1;
			else if (a < b)
				b >>= 1;
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
