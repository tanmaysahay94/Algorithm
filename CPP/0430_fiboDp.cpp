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

vector<LL> dp(1000000, -1);
LL mod = 1e9 + 7;

LL fib(LL n)
{
	if (n == 0 or n == 1)
	{
		dp[n] = n;
		return dp[n];
	}
	if (dp[n] != -1)
		return dp[n];
	else
	{
		dp[n] = (fib(n - 1) + fib(n - 2)) % mod;
		return dp[n];
	}
}

int main()
{
	LL n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
