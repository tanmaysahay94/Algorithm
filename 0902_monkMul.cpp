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
	int n;
	cin >> n;
	priority_queue<LL> pq;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		pq.push(val);
		if (i == 1 or i == 0)
			cout << "-1\n";
		else
		{
			LL ans = 1;
			vector<int> v;
			for (int j = 0; j < 3; j++)
			{
				v.push_back(pq.top());
				pq.pop();
			}
			for (auto a: v)
				ans *= a;
			for (auto a: v)
				pq.push(a);
			cout << ans << '\n';
		}
	}
	return 0;
}
