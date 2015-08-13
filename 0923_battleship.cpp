#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, a, m;
	cin >> n >> k >> a >> m;
	set<int> S;
	S.insert(0);
	S.insert(n + 1);
	int cnt = (n + 1) / ++a;
	bool possible = false;
	int ans = -1;
	for (int i = 0; i < m; i++)
	{
		int loc;
		cin >> loc;
		if (possible)
			continue;
		auto foo = S.lower_bound(loc);
		auto bar(foo);
		bar--;
		cnt -= (*foo - *bar)/ a;
		cnt += (*foo - loc) / a;
		cnt += (loc - *bar) / a;
		S.insert(loc);
		if (cnt < k)
			possible = true, ans = i + 1;
	}
	cout << ans;
	return 0;
}
