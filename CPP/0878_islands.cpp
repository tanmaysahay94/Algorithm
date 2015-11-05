#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<PLL, LL> PPLL;

void oops()
{
	cout << "No";
	exit(0);
}

int main()
{
	optimizeIO();
	LL n, m;
	cin >> n >> m;
	vector<PLL> isl(n);
	for (int i = 0; i < n; i++)
		cin >> isl[i].first >> isl[i].second;
	vector<PPLL> diff;
	for (int i = 1; i < n; i++)
	{
		PPLL foo;
		PLL bar = make_pair(isl[i].second - isl[i - 1].first, isl[i].first - isl[i - 1].second);
		LL buz = i - 1;
		foo = make_pair(bar, buz);
		diff.push_back(foo);
	}
	set<PLL> bridge;
	for (int i = 0; i < m; i++)
	{
		LL len;
		cin >> len;
		bridge.insert(make_pair(len, i + 1));
	}
	if (m < n - 1)
		oops();
	sort(diff.begin(), diff.end());
	vector<LL> ans(n - 1, -1);
	for (auto d: diff)
	{
		set<PLL>::iterator best = bridge.upper_bound(PLL(d.first.second - 1, (LL) (1e7 + 3)));
		if (best == bridge.end())
			oops();
		PLL foo = *best;
		if (d.first.second <= foo.first and foo.first <= d.first.first)
		{
			ans[d.second] = (*best).second;
			bridge.erase(best);
		}
		else
			oops();
	}
	cout << "Yes\n";
	for (auto A: ans)
		cout << A << ' ';
	return 0;
}
