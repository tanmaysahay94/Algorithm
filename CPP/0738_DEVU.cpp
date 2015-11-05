#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> v;
int n;
map<pair<vector<int>, int>, pair<double, double> > expect;

pair<double, double> calc(int end, int val)
{
	if (expect.count(make_pair(v, end)))
		return expect[make_pair(v, end)];
	pair<double, double> &ret = expect[make_pair(v, end)];
	ret.first = ret.second = 0;
	if (val == n)
	{
		ret.second = 1;
		for (int j = n; j >= 0; j--)
			if (v[j] != 0)
			{
				ret.first = v[j];
				return ret;
			}
		return ret;
	}
	for (int j = 0; j < n; j++)
	{
		int foo = v[j];
		if (j == end)
			foo--;
		if (foo < 1)
			continue;
		v[j]--;
		v[j + 1]++;
		pair<double, double> tmp = calc(j + 1, val + 1);
		tmp.first *= foo;
		tmp.second *= foo;
		ret.first += tmp.first;
		ret.second += tmp.second;
		v[j]++;
		v[j + 1]--;	
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		v.resize(n + 1);
		for (int i = 0; i < n + 1; i++)
			v[i] = 0;
		v[0] = n - 1;
		v[1] = 1;
		pair<double, double> ans = calc(1, 1);
		printf("%.6lf\n", ans.first/ans.second);
	}
	return 0;
}
