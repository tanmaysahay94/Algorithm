#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool cmp(pair<LL, LL>& a, pair<LL, LL>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
int main()
{
	LL n, k;
	cin >> n >> k;
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second;
		v[i].first = 10 - (v[i].second % 10);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		int diff = v[i].first;
		if (k < diff)
			break;
		v[i].second += diff;
		if (v[i].second > 100)
		{
			diff -= v[i].second - 100;
			v[i].second = 100;
		}
		k -= diff;
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
		ans += v[i].second / 10;
	LL foo = 0;
	for (int i = 0; i < n; i++)
		foo += 100 - v[i].second;
	ans += min(foo / 10, k / 10);
	cout << ans;
	return 0;
}
