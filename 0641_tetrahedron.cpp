#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL mod = 1e9 + 7;
vector<VI> v(4, VI (4, 1));

LL fastPow(int k)
{
	vector<VI> ret(4, VI (4, 0));
	for (int i = 0; i < 4; i++)
		ret[i][i] = 1;
	while (k)
	{
		vector<VI> tmp(4, VI (4));
		if (k & 1)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						tmp[i][j] = (tmp[i][j] % mod + ((ret[i][k] % mod) * (v[k][j] % mod)) % mod) % mod;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					ret[i][j] = tmp[i][j];
					tmp[i][j] = 0;
				}
		}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					tmp[i][j] = (tmp[i][j] % mod + ((v[i][k] % mod) * (v[k][j] % mod)) % mod) % mod;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				v[i][j] = tmp[i][j];
		k >>= 1;
	}
	return ret[3][3];
}

int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < 4; i++)
		v[i][i] = 0;
	cout << fastPow(k) << endl;
	return 0;
}
