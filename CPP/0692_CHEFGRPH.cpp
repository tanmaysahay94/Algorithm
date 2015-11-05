#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e9 + 7;

long long modFastPow(long long a, long long b)
{
	long long ret = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	optimizeIO();
	long long n, m, k, w, x, y, z, ans = 0, finalVal = 0;
	map<long long, long long> line;
	map<pair<long long, long long>, long long> point;
	vector<pair<pair<long long, long long>, pair<long long, long long> > > a;
	vector<pair<pair<long long, long long>, pair<long long, long long> > >::iterator it;
	vector<pair<long long, long long> > b;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> w >> x >> y >> z;
		b.push_back(make_pair(w, x));
		a.push_back(make_pair(make_pair(w, x), make_pair(0, 0)));
		a.push_back(make_pair(make_pair(y, z), make_pair(1, i)));
	}
	sort(a.begin(), a.end());
	line[0] = 1;
	point[make_pair(0, 0)] = 1;
	for (it = a.begin(); it != a.end(); it++)
	{
		if (finalVal < it->first.first - 1)
		{
			line[it->first.first - 1] = (modFastPow(m, it->first.first - finalVal - 1) * line[finalVal]) % mod;
			finalVal = it->first.first - 1;
		}
		if (point.find(it->first) == point.end())
			point[it->first] = line[it->first.first - 1];
		if (it->second.first == 1)
		{
			if (finalVal < it->first.first)
			{
				if (it->first.first <= n)
					line[it->first.first] = (m * line[it->first.first - 1]) % mod;
				else
					line[it->first.first] = line[it->first.first - 1];
				finalVal = it->first.first;
			}
			long long temp = point[b[it->second.second]];
			point[it->first] = (point[it->first] + temp) % mod;
			line[it->first.first] = (line[it->first.first] + temp) % mod;
		}
	}
	if (finalVal < n)
		line[n] = (line[finalVal] * modFastPow(m, n - finalVal)) % mod;
	ans = point[make_pair(n + 1, 0)];
	if (ans == 0)
		ans = line[n];
	cout << ans << endl;
	return 0;
}
