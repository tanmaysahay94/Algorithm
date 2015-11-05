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

VLL primes, isPrime(1000010, 1);
vector<vector<LL> > factorMap(1000010);

void sieve()
{
	isPrime[0] = isPrime[1] = 0;
	LL i, j;
	for (i = 2; i < 1000010; i++)
	{
		if (isPrime[i])
		{
			primes.pb(i);
			factorMap[i].pb(i);
			for (j = 2 * i; j < 1000010; j += i)
			{
				isPrime[j] = 0;
				primes.pb(j);
				factorMap[j].pb(i);
			}
		}
	}
}

int main()
{
	sieve();
	LL t;
	SLL(t);
	while (t--)
	{
		LL n;
		SLL(n);
		VLL arr(n), dp(n, 0);
		VLL latest(1000010, -1), prev(1000010, -1);
		for (int i = 0; i < n; i++)
		{
			SLL(arr[i]);
			LL val = arr[i];
			for (int j = 0; j < factorMap[val].size(); j++)
			{
				prev[i] = max(prev[i], latest[factorMap[val][j]]);
				latest[factorMap[val][j]] = i;
			}
		}
		LL ans = 0;
		dp[0] = 1;
		for (int i = 1; i < n; i++)
		{
			LL length = i - prev[i];
			if (length > dp[i - 1])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = length;
			ans = max(ans, dp[i]);
		}
		if (ans > 1) cout << ans;
		else cout << "-1";
		cout << endl;
	}
	return 0;
}
