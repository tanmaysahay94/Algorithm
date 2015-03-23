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
	int t;
	cin >> t;
	while (t--)
	{
		int s, c, k;
		cin >> s >> c >> k;
		unsigned long long ans = 0;
		if (s >= k)
			ans += 3;
		unsigned long long t = 0;
		if (s >= k)
			t = ((1LL) << (s - k + 1)) - 1;
		if (s <= c and k == 1)
			t = t + ((1LL) << c) - ((1LL) << s);
		else if (c <= s - k)
			t -= ((1LL) << (s - k));
		ans += t << 1;
		cout << ans << endl;
	}
	return 0;
}
