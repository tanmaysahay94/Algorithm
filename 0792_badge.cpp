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
	vector<int> v(n);
	vector<int> cnt(100000);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		cnt[v[i]]++;
	}
	long long ans = 0;
	for (int i = 1; i <= 3000; i++)
	{
		if (cnt[i] < 2)
			continue;
		while (cnt[i] > 1)
		{
			int j = i;
			while (cnt[j])
				j++;
			cnt[j] = 1;
			ans += j - i;
			cnt[i]--;
		}
	}
	cout << ans << endl;
	return 0;
}
