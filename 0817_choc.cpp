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
	LL n, m, k;
	cin >> n >> m >> k;
	if (k > n + m - 2)
	{
		cout << "-1\n";
		return 0;
	}
	LL ans = 0;
	if (m > k) ans = m / (k + 1) * n;
	if (n > k) ans = max(ans, n / (k + 1) * m);
	if (k >= max(m, n)) ans = max(ans, max(n / (k - m + 2), m / (k - n + 2)));
	cout << ans << endl;
	/*
	int pc = 1;
	vector<int> ncut, mcut;
	while (pc < n)
	{
		ncut.push_back(pc - 1);
		pc = n / (n / pc) + 1;
	}
	pc = 1;
	while (pc < m)
	{
		mcut.push_back(pc - 1);
		pc = n / (n / pc) + 1;
	}*/
	return 0;
}
