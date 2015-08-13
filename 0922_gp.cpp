#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n, k;
	cin >> n >> k;
	map<LL, LL> left, right;
	vector<LL> lreq(n, 0), rreq(n, 0), v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		left[v[i - 1]]++;
		if (v[i] % k == 0)
			lreq[i] = left[v[i] / k];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		right[v[i + 1]]++;
		rreq[i] = right[v[i] * k];
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
		ans += lreq[i] * rreq[i];
	cout << ans;
	return 0;
}
