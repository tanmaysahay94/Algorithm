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
	LL inv = modInverse(b, m);
	printf("Inverse: %lld div: %lld\n", inv, (a * inv) % m);
}
