#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<char, int> mp;
set<int> v;

bool check(int mask)
{
	int bar[1000000] = {0};
	set<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		bar[mask & (*it)]++;
		if (bar[mask & (*it)] > 1)
			return false;
	}
	return true;
}

int main()
{
	mp['R'] = 0;
	mp['G'] = 1;
	mp['B'] = 2;
	mp['Y'] = 3;
	mp['W'] = 4;
	optimizeIO();
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int foo = 1 << (s[1] - '1');
		foo |= 1 << (mp[s[0]] + 5);
		v.insert(foo);
	}
	int ans = 100;
	for (int mask = 0; mask < 1024; mask++)
		if (check(mask))
			ans = min(ans, __builtin_popcount(mask));
	cout << ans << endl;
	return 0;
}
