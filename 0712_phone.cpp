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
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> phone(111111), loc(111111);
	for (long long i = 1; i <= n; i++)
	{
		long long id;
		cin >> id;
		phone[i] = id;
		loc[id] = i;
	}
	long long ans = 0;
	for (long long i = 0; i < m; i++)
	{
		long long id;
		cin >> id;
		long long currLoc = loc[id];
		long long moves = (currLoc - 1) / k + 1;
		ans += moves;
		if (currLoc > 1)
		{
			long long a = phone[currLoc - 1];
			swap(phone[currLoc - 1], phone[currLoc]);
			swap(loc[id], loc[a]);
		}
	}
	cout << ans << endl;
	return 0;
}
