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
	LL n, l, r, x;
	cin >> n >> l >> r >> x;
	int ans = 0;
	vector<LL> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c.begin(), c.end());
	int lim = 1 << n;
	for (int mask = 3; mask < lim; mask++)
	{
		int tmp = mask;
		int idx = 0;
		LL sum = 0;
		vector<LL> problems;
		while (tmp)
		{
			if (tmp & 1)
			{
				problems.push_back(c[idx]);
				sum += c[idx];
			}
			idx++;
			tmp >>= 1;
		}
		if (sum >= l and sum <= r and problems.size() >= 2 and (*(problems.rbegin()) - *(problems.begin()) >= x))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
