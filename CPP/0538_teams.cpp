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

LL nC2(LL n)
{
	return (n * (n - 1))>>1;
}

LL f1(LL n, LL m)
{
	return nC2(n - m + 1);
}

LL f2(LL n, LL m)
{
	return (m - n%m) * nC2(n/m) + n%m * nC2(n/m + 1);
}

int main()
{
	LL n, m;
	cin >> n >> m;
	LL a = f1(n, m);
	LL b = f2(n, m);
	printf("%lld %lld\n", min(a, b), max(a, b));
	return 0;
}
