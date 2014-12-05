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
	cout.precision(3);
	LL t;
	cin >> t;
	while (t--)
	{
		LL n, i;
		cin >> n >> i;
		if (i == 1)
			printf("%.3lf\n", 1/((double)n));
		else
		{
			double N = (double) n;
			double I = (double) i;
			double ans = (N - I + 1);
			ans /= (N - I + 2);
			printf("%.3lf\n", ans);
		}
	}
	return 0;
}
