#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

const LL mxn = 101;

LL cnt[mxn][mxn];

int main()
{
	optimizeIO();
	memset(cnt, 0, sizeof(cnt));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				cnt[i][j]++;
	}
	LL ans = 0;
	for (int i = 1; i < mxn; i++)
		for (int j = 1; j < mxn; j++)
			ans += cnt[i][j];
	cout << ans << '\n';
	return 0;
}
