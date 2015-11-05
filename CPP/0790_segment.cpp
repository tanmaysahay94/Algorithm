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
	int v1, v2, t, d;
	cin >> v1 >> v2 >> t >> d;
	vector<int> v(t);
	v[0] = v1;
	v[t-1] = v2;
	for (int i = 1; i + 1 < t; i++)
	{
		int a = v[i - 1] + d;
		int b = v[t - 1] + d * (t - 1 - i);
		v[i] = min(a, b);
	}
	int ans = 0;
	for (int i = 0; i < t; i++)
		ans += v[i];
	cout << ans << endl;
	return 0;
}
