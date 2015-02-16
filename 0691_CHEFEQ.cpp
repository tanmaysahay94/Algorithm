#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin >> t;
	vector<long long> cnt(111111);
	while (t--)
	{
		long long n, val;
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> val;
			cnt[val]++;
			ans = max(ans, cnt[val]);
		}
		cout << n - ans << endl;
		cnt = vector<long long> (111111);
	}
	return 0;
}
