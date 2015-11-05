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
	LL n, p, x, val;
	cin >> n >> p >> x;
	LL ans = LLONG_MIN;
	LL idx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		LL score = p * val;
		if (score > ans)
		{
			ans = score;
			idx = i;
		}
		p -= x;
	}
	cout << idx + 1;
	return 0;
}
