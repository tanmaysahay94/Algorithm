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

LL f(LL val)
{
	LL count = 0;
	while (val)
	{
		count++;
		val >>= 1;
	}
	return count;
}

int main()
{
	ULL t, step, v;
	double high, nr, dr;
	SULL(t);
	while (t--)
	{
		scanf("%lf", &high);
		SULL(step);
		LL log2 = f(step);
		dr = 1ULL << log2;
		v = 1ULL << (log2 - 1);
		step %= v;
		nr = step * 2 + 1ULL;
		printf("%.15lf\n", high * nr / dr);
	}
	return 0;
}
