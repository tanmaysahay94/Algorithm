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
	string s;
	cin >> s;
	int mx = 0;
	for (int i = 0; i < (int) s.length(); i++)
		mx = max(mx, s[i] - '0');
	vector<vector<char> > v(mx, vector<char> (s.length(), '0'));
	for (int i = 0; i < (int) s.length(); i++)
		for (int j = 0; j < s[i] - '0'; j++)
			v[j][i] = '1';
	cout << mx << endl;
	for (int i = 0; i < mx; i++)
	{
		int tmp = 0;
		for (int j = 0; j < (int) v[i].size(); j++)
			tmp = 10 * tmp + v[i][j] - '0';
		cout << tmp << ' ';
	}
	cout << endl;
	return 0;
}
