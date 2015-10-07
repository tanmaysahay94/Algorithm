#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int, int> mp;
	priority_queue<int> pq;
	int n;
	cin >> n;
	int s = n * n;
	for (int i = 0; i < s; i++)
	{
		int val;
		cin >> val;
		mp[val]++;
		pq.push(val);
	}
	vector<int> ans;
	while (pq.size())
	{
		int val = pq.top();
		pq.pop();
		if (mp[val] > 0)
		{
			for (int i = 0; i < (int) ans.size(); i++)
				mp[__gcd(val, ans[i])] -= 2;
			ans.push_back(val);
			mp[val]--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	return 0;
}
