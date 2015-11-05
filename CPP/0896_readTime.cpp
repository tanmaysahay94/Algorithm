#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool f(long long t, vector<long long>& h, vector<long long>& p)
{
	int seen = 0;
	for (int i = 0; i < (int) h.size(); i++)
	{
		if (h[i] + t < p[seen])
			continue;
		if (h[i] - t > p[seen])
			return false;
		long long foo = max(p[seen] + t - abs(h[i] - p[seen]), h[i] + (t - abs(h[i] - p[seen])) / 2);
		while (p[seen] <= foo and seen < (int) p.size())
			seen++;
		if (seen == (int) p.size())
			return true;
	}
	return false;
}

int main()
{
	optimizeIO();
	int n, m;
	cin >> n >> m;
	vector<long long> h(n), p(m);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];
	long long low = 0, high = 1e12+ 5;
	while (low != high - 1)
	{
		long long mid = (low + high) / 2;
		if (f(mid, h, p))
			high = mid;
		else
			low = mid;
	}
	if (f(0, h, p))
		high = 0;
	cout << high;
	return 0;
}
