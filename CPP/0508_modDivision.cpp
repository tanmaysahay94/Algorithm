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

LL mod(LL a, LL n)
{
	return ((a%n) + n)%n;
}

LL _extendedEuclid(LL a, LL b, LL& x, LL& y)
{
	LL xx = y = 0;
	LL yy = x = 1;
	while (b)
	{
		LL q = a/b;
		LL t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}

LL _modInverse(LL a, LL n)
{
	LL x, y;
	LL d = _extendedEuclid(a, n, x, y);
	if (d > 1)
		return -1;
	return mod(x, n);
}

pair<LL, pair<LL, LL> > extendedEuclid(LL a, LL b)
{
	LL x = 1, y = 0;
	LL xLast = 0, yLast = 1;
	LL q, r, m, n;
	while (a)
	{
		q = b/a;
		r = b%a;
		m = xLast - q*x;
		n = yLast - q*y;
		xLast = x, yLast = y;
		x = m, y = n;
		b = a, a = r;
	}
	return mp(b, mp(xLast, yLast));
}

LL modInverse(LL a, LL b)
{
	return (extendedEuclid(a, b).second.first + b) % b;
}

int main()
{
	LL a, b, m;
	cin >> a >> b >> m;
	LL inv = _modInverse(b, m);
	printf("Inverse: %lld div: %lld\n", inv, (a * inv) % m);
}
