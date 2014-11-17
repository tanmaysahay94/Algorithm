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

vector<vector<pair<LL, LL> > > factor(100010);
VLL isPrime(100010, 1);
vector<pair<LL, LL> > query;
map<LL, LL> nr, dr;
map<LL, LL>::iterator map_it;
VLL powers, answers, inverse;

LL powMod(LL a, LL b, LL p)
{
	a = a % p;
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret;
}

LL etf(LL m)
{
	LL ret = 1, i, pow;
	for (i = 2; m != 1; i++)
	{
		pow = 1;
		if (i > sqrt(m))
			break;
		while (!(m % i))
		{
			m /= i;
			pow *= i;
		}
		ret *= (pow - (pow/i));
	}
	if (m != 1)
		ret *= (m - 1);
	return ret;
}

void getFactors()
{
	isPrime[0] = isPrime[1] = 0;
	factor[1].pb(mp(1, 1));
	for (LL i = 2; i <= 100001; i++)
	{
		if (isPrime[i])
		{
			factor[i].pb(mp(i, 0));
			for (LL j = 2 * i; j <= 100001; j += i)
			{
				isPrime[j] = 0;
				factor[j].pb(mp(i, 0));
			}
		}
	}
	for (LL i = 2; i <= 100001; i++)
	{
		LL val = i;
		for (LL idx = 0; idx < factor[i].size(); idx++)
		{
			while (val % factor[i][idx].f == 0)
			{
				val /= factor[i][idx].f;
				factor[i][idx].s++;
			}
			factor[i][idx].s *= i;
		}
	}
}

int main()
{
	getFactors();
	LL t, n, m, q, r;
	SLL(t);
	while (t--)
	{
		nr.clear();
		dr.clear();
		SLL(n), SLL(m), SLL(q);
		if (n <= 500)
		{
			query.resize(q);
			answers.resize(q);
			for (LL i = 0; i < q; i++)
			{
				SLL(r);
				query[i] = mp(min(r, n - r), i);
			}
			sortv(query);
			LL lim, start = 1, end = n;
			for (LL i = 0; i < q; i++)
			{
				lim = query[i].f;
				for (; start <= lim; start++)
				{
					LL sz = factor[start].size();
					for (LL k = 0; k < sz; k++)
					{
						LL val = factor[start][k].f;
						LL v = dr[val];
						v += factor[start][k].s;
						dr[val] = v;
					}
				}
				start = lim + 1;
				for (; end >= n - lim + 1; end--)
				{
					LL sz = factor[end].size();
					for (LL k = 0; k < sz; k++)
					{
						LL val = factor[end][k].f;
						LL v = nr[val];
						v += factor[end][k].s;
						nr[val] = v;
					}
				}
				end = n - lim;
				LL ans = 1;
				for (map_it = nr.begin(); map_it != nr.end(); map_it++)
				{
					LL prod = powMod(map_it->first, map_it->second - dr[map_it->first], m);
					ans = (ans * prod) % m;
				}
				if (ans < 0)
					ans += m;
				answers[query[i].s] = ans;
			}
			for (LL i = 0; i < q; i++)
				printf("%lld\n", answers[i]);
		}
		else
		{
			powers.resize(n + 1);
			inverse.resize(n + 1);
			answers.resize(n + 1);
			inverse[0] = powers[0] = 1;
			LL phi = etf(m);
			for (LL i = 1; i <= n; i++)
			{
				powers[i] = powMod(i%m, i, m);
				inverse[i] = powMod(powMod(i, phi - 1, m), i, m);
			}
			answers[1] = answers[n - 1] = powers[n];
			for (LL i = 2; i <= n/2; i++)
			{
				LL val = answers[i - 1];
				val = (val * powers[n - i + 1]) % m;
				val = (val * inverse[i]) % m;
				answers[i] = answers[n - i] = val;
			}
			while (q--)
			{
				SLL(r);
				printf("%lld\n", answers[r]);
			}
		}
	}
	return 0;
}
