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
	long long n, val, high = -1;
	vector<long long> cnt(1000009);
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> val;
		cnt[val]++;
		high = max(high, val);
	}
	for (long long len = high; len > 0; len--)
		if (cnt[len] & 1)
		{
			cnt[len]--;
			if (cnt[len - 1] > 0)
				cnt[len - 1]++;
		}
	multiset<long long> s;
	for (long long len = high; len > 0; len--)
	{
		int c = cnt[len];
		c >>= 1;
		for (int i = 0; i < c; i++)
			s.insert(-len);
	}
	long long ans = 0;
	while (s.size() > 1)
	{
		long long a = -*s.begin();
		s.erase(s.begin());
		long long b = -*s.begin();
		s.erase(s.begin());
		ans += a * b;
	}
	cout << ans << endl;
	return 0;
}
