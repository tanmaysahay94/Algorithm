#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin >> n;
	vector<LL> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	if (v.size() == 1)
	{
		cout << -1;
		return 0;
	}
	if (v.size() == 2)
	{
		LL d = v[1] - v[0];
		set<LL> ans;
		ans.insert(v[0] - d);
		ans.insert(v[1] + d);
		if (d % 2 == 0)
			ans.insert(v[0] + (d >> 1));
		cout << ans.size() << '\n';
		for (auto a: ans)
			cout << a << ' ';
		return 0;
	}
	map<LL, LL> cnt;
	for (int i = 1; i < n; i++)
		cnt[v[i] - v[i - 1]]++;
	if (cnt.size() == 1)
	{
		set<LL> ans;;
		LL d = v[1] - v[0];
		ans.insert(v[0] - d);
		ans.insert(v[n - 1] + d);
		cout << ans.size() << '\n';
		for (auto a: ans)
			cout << a << ' ';
		return 0;
	}
	if (cnt.size() > 2)
	{
		cout << 0;
		return 0;
	}
	vector<pair<LL, LL> > foo;
	for (auto c: cnt)
		foo.push_back(c);
	sort(foo.begin(), foo.end());
	if (foo[1].second > 1)
	{
		cout << 0;
		return 0;
	}
	if (foo[1].first != (foo[0].first << 1))
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i < n; i++)
		if (v[i] - v[i - 1] == foo[1].first)
		{
			cout << 1 << '\n';
			cout << ((v[i] + v[i - 1]) >> 1);
			break;
		}
	return 0;
}
