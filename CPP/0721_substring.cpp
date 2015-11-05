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
	long long mp[26], ans(0);
	vector<int> pos[111111];
	for (int i = 0; i < 26; i++)
		cin >> mp[i];
	string str;
	cin >> str;
	int length = str.length();
	str = string("?") + str;
	vector<long long> presum(length + 1, 0);
	for (long long i = 1; i <= length; i++)
	{
		presum[i] = presum[i - 1] + mp[str[i] - 'a'];
		pos[str[i] - 'a'].push_back(i);
	}
	for (long long ch = 0; ch < 26; ch++)
	{
		map<long long, long long> mp;
		for (int i = 0; i < pos[ch].size(); i++)
		{
			int p = pos[ch][i];
			ans += mp[presum[p - 1]];
			mp[presum[p]]++;
		}
		mp.clear();
	}
	cout << ans << endl;
	return 0;
}
