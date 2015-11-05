#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int main()
{
	optimizeIO();
	LL n, d;
	cin >> n >> d;
	LL a, b;
	cin >> a >> b;
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
	{
		LL x, y;
		cin >> x >> y;
		v[i].first = a * x + b * y;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	int cnt = -1;
	LL foo = 0;
	vector<LL> ans;
	while (cnt + 1 < n and v[cnt + 1].first + foo <= d)
	{
		foo += v[cnt + 1].first;
		ans.push_back(v[++cnt].second);
	}
	cout << ans.size() << '\n';
	for (auto a: ans)
		cout << a << ' ';
	return 0;
}
