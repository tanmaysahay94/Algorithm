#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

LL n;

LL foo(vector<pair<LL, LL> >& v)
{
	if (v[0].first > 0)
		return v[0].second;
	if (v[n - 1].first < 0)
		return v[n - 1].second;
	LL left, right;
	for (LL i = 0; i < n; i++)
		if (v[i].first > 0)
		{
			left = i - 1;
			right = i;
			break;
		}
	LL v1 = 0;
	LL l = left, r = right, state = 0;
	while ((state and r < n) or (not state and l >= 0))
	{
		if (state)
			v1 += v[r++].second;
		else
			v1 += v[l--].second;
		state ^= 1;
	}
	l = left, r = right, state = 1;
	LL v2 = 0;
	while ((state and r < n) or (not state and l >= 0))
	{
		if (state)
			v2 += v[r++].second;
		else
			v2 += v[l--].second;
		state ^= 1;
	}
	return max(v1, v2);
}

int main()
{
	optimizeIO();
	cin >> n;
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	cout << foo(v);
	return 0;
}
