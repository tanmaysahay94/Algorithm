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
	cin >> n;
	int keys[26] = {0};
	string s;
	cin >> s;
	for (int i = 0; i < (int) s.length(); i += 2)
	{
		int c = s[i] - 'a';
		int C = s[i + 1] - 'A';
		keys[c]++;
		if (keys[C] > 0)
			keys[C]--;
		else
			ans++;
	}
	cout << ans << endl;
	return 0;
}
