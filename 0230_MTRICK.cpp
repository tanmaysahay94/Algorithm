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

LL multiply(LL a, LL b, LL mod)
{
	if (b == 0)
		return 0;
	LL ret = multiply(a, b >> 1, mod);
	ret = (ret + ret) % mod;
	if (b & 1)
		ret = (ret + a) % mod;
	ret %= mod;
	return ret;
}

int main()
{
	string w;
	LL t, n, a, b, c;
	VLL v(1010);
	SLL(t);
	while (t--)
	{
		SLL(n);
		LL dir = 1, toAdd = 0, toMul = 1, start = 0, end = n - 1;
		v.resize(n);
		for (int i = 0; i < n; i++)
			SLL(v[i]);
		SLL(a), SLL(b), SLL(c);
		a %= c, b %= c;
		cin >> w;
		for (int i = 0; w[i]; i++)
		{
			if (w[i] == 'A')
				toAdd = (toAdd % c + a) % c;
			else if (w[i] == 'M')
			{
				toAdd = multiply(toAdd, b, c) % c;
				toMul = multiply(toMul, b, c) % c;
			}
			else if (w[i] == 'R')
			{
				swap(start, end);
				dir *= -1;
			}
			v[start] = multiply(v[start], toMul, c) % c;
			v[start] = (v[start] + toAdd) % c;
			printf("%lld ", v[start]);
			start += dir;
		}
		printf("\n");
	}
	return 0;
}
