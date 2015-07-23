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
	LL m, n;
	cin >> m >> n;
	priority_queue<LL> pq;
	for (int i = 0; i < m; i++)
	{
		LL val;
		cin >> val;
		pq.push(val);
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		LL foo = pq.top();
		pq.pop();
		ans += foo;
		foo--;
		pq.push(foo);
	}
	cout << ans << '\n';
	return 0;
}
