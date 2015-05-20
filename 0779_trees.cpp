#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	vector<pair<long long, long long> > v(n);
	int ans = 1;
	if (n > 1)
		ans++;
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	long long lm = v[0].first;
	long long tmp = 0;
	for (int i = 1; i < n-1; i++)
	{
		lm = max(lm, v[i-1].first);
		if (lm < v[i].first - v[i].second)
		{
			lm = v[i].first;
			tmp++;
		}
		else if (v[i].first + v[i].second < v[i+1].first)
		{
			lm = v[i].first + v[i].second;
			tmp++;
		}
	}
	cout << ans+tmp<<endl;
	return 0;
}
