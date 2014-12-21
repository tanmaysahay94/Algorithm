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

bool win(int n)
{
	if (n == 2 or n == 17)
		return true;
	if (n == 16 or n == 34 or n == 289)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return true;
	return false;
}

int main()
{
	int t, n;
	si(t);
	while (t--)
	{
		si(n);
		if (win(n))
			printf("Mike\n");
		else
			printf("Tom\n");
	}
	return 0;
}
