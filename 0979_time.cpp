#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ends[maxn];
	vector<pair<int, int> > queries(n);
	set<int> S;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		queries[i] = make_pair(l, r);
		S.insert(l), S.insert(r);
	}
	int curr = 1;
	map<int, int> mp;
	for (auto i: S)
		mp[i] = curr++;
	for (int i = 0; i < n; i++)
	{
		int l = mp[queries[i].first];
		int r = mp[queries[i].second];
		ends[l].push_back(r);
	}
	vector<int> HE(maxn + 1, INT_MIN);
	for (int i = 1; i < maxn; i++)
	{
		sort(ends[i].begin(), ends[i].end());
		if (ends[i].empty())
			HE[i] = HE[i - 1];
		else
			HE[i] = max(HE[i - 1], *(ends[i].rbegin()));
	}
	int ans = 0;
	for (int i = 2; i < maxn; i++)
		if (not ends[i].empty())
			ans += lower_bound(ends[i].begin(), ends[i].end(), HE[i - 1]) - ends[i].begin();
	cout << ans;
	return 0;
}
