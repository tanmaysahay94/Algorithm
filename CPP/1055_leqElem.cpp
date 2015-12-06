#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n, m;
	scanf("%lld%lld", &n, &m);
	vector<LL> v1(n), v2(m), v3(n + m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &v1[i]);
		v3[i] = v1[i];
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &v2[i]);
		v3[i + n] = v2[i];
	}
	sort(v3.begin(), v3.end());
	map<LL, LL> mp;
	for (int i = 0; i < (int) v3.size(); i++)
		if (mp.count(v3[i]) == 0)
			mp[v3[i]] = i;
	for (auto &v: v1)
		v = mp[v];
	for (auto &v: v2)
		v = mp[v];
	sort(v1.begin(), v1.end());
	for (int i = 0; i < m; i++)
		cout << upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
	return 0;
}
