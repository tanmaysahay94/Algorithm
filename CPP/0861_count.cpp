#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

LL f(LL n)
{
	return (n * (n + 1)) / 2;
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, LL> mp;
	for (int i = 0; i < n; i++)
		mp[s[i]]++;
	LL ans = 0;
	for (map<char, LL>::iterator it = mp.begin(); it != mp.end(); it++)
		ans += f((*it).second);
	cout << ans;
	return 0;
}
