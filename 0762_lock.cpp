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
	int n, ans = 0;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
		ans += min(abs(s1[i] - s2[i]), 10- abs(s1[i] - s2[i]));
	cout << ans << endl;
	return 0;
}
