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

LL gcd(LL a, LL b)
{
	if (not b) return a;
	return gcd(b, a % b);
}

int main()
{
	LL t, n;
	SLL(t);
	while (t--)
	{
		SLL(n);
		VLL arr(n);
		for (int i = 0; i < n; i++)
			SLL(arr[i]);
		LL g = arr[0];
		for (int i = 0; i < n; i++)
			g = gcd(g, arr[i]);
		if (g == 1)
			printf("%lld\n", n);
		else			
			printf("-1\n");
	}
	return 0;
}
