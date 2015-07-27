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
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		if (mp.count(r))
			mp[r] = min(mp[r], c);
		else
			mp[r] = c;
	}
	priority_queue<int> pq;
	for (auto M: mp)
		pq.push(M.second);
	int i = 0;
	int ans = 0;
	while (i < k)
	{
		int foo = pq.top();
		pq.pop();
		foo--;
		if (foo < 0)
			break;
		ans++;
		pq.push(foo);
		i++;
	}
	cout << ans;
	return 0;
}
