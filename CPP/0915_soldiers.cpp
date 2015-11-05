#include <bits/stdc++.h>

using namespace std;

#define si(x) scanf("%lld", &x)
#define pi(x) printf("%lld", x)

typedef long long LL;
typedef pair<LL, LL> PLL;

int main()
{
	LL n, m, x, y;
	si(n), si(m), si(x), si(y);
	vector<LL> v(n);
	set<PLL> u;
	for (LL i = 0; i < n; i++)
		si(v[i]);
	for (LL i = 0; i < m; i++)
	{
		LL vest;
		si(vest);
		u.insert({vest, i});
	}
	vector<PLL> ans;
	for (int i = 0; i < n; i++)
	{
		set<PLL>::iterator it = u.lower_bound(make_pair(v[i] - x, (LL) -1));
		if (it == u.end())
			continue;
		PLL res = *it;
		if (v[i] + y >= res.first and res.first >= v[i] - x and res.second < m)
		{
			ans.push_back(make_pair(i + 1, res.second + 1));
			u.erase(it);
		}
	}
	pi((LL)ans.size());puts("");
	for (auto a: ans)
		pi(a.first), printf(" "), pi(a.second), puts("");
	return 0;
}
