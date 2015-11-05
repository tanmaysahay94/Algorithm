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
	int n;
	cin >> n;
	vector<long long> l(n), c(n);
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	// use maps like this when you want all possible values of some function
	map<long long, long long> mp;
	map<long long, long long>::iterator it;
	mp[0] = 0;
	for (int i = 0; i < n; i++)
		for (it = mp.begin(); it != mp.end(); it++)
		{
			long long gcd = __gcd(it->first, l[i]);
			if (mp.count(gcd))
				mp[gcd] = min(mp[gcd], it->second + c[i]);
			else
				mp[gcd] = it->second + c[i];
		}
	if (mp.count(1))
		cout << mp[1] << endl;
	else
		cout << -1 << endl;
	return 0;
}
