#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef int ULL;

int f(int val)
{
	return (val) * (val + 1) >> 1;
}

int main()
{
	string s;
	int k, i, val, high = 0, ans = 0;
	cin >> s >> k;
	vector<int> w(26);
	for (i = 0; i < 26; i++)
	{
		cin >> w[i];
		high = max(high, w[i]);
	}
	for (i = 0; s[i]; i++)
		ans += (i + 1) * w[s[i] - 'a'];
	int len = s.length(); int great = len + k;
	cout << ans + (high * (f(great) - f(len))) << endl;
	return 0;
}
