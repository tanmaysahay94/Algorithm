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

vector<VLL> operator*(vector<VLL>& a, vector<VLL>& b)
{
	vector<VLL> ret(a.size(), VLL(a.size()));
	for (int i = 0; i < (int) a.size(); i++)
		for (int j = 0; j < (int) b.size(); j++)
			for (int k = 0; k < (int) a.size(); k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= mod;
			}
	return ret;
}

void powMod(vector<VLL>& v, LL n)
{
	vector<VLL> ans(v.size(), VLL(v.size()));
	for (int i = 0; i < (int) ans.size(); i++)
		ans[i][i] = 1;
	while (n)
	{
		if (n & 1)
			ans = ans * v;
		v = v * v;
		n >>= 1;
	}
	v = ans;
}

int main()
{
	int t;
	si(t);
	while (t--)
	{
		LL n, m;
		sll(n), sll(m);
		n--;
		vector<VLL> mEven(m, VLL(m));
		vector<VLL> mOdd = mEven;
		for (LL i = 1; i < m; i++)
			mEven[i][i-1] = mEven[i-1][i] = 1;
		mOdd[0][0] = 1;
		for (LL i = 1; i < m; i++)
			mOdd[i][i-1] = mOdd[i][i] = mOdd[i-1][i] = 1;
		mOdd = mOdd * mEven;
		powMod(mOdd, n/2);
		if (n%2)
			mOdd = mEven * mOdd;
		LL ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				ans = (ans + mOdd[i][j]) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
