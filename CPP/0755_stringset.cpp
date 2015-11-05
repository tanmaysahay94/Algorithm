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
	int flg[26] = {0};
	int k;
	cin >> k;
	string s;
	cin >> s;
	int cnt = 1;
	vector<int> start(s.length());
	start[0] = 1;
	flg[s[0] - 'a'] = 1;
	for (int i = 1; cnt < k and i < (int) s.length(); i++)
		if (not flg[s[i] - 'a'])
			flg[s[i] - 'a'] = 1, start[i] = 1, cnt++;
	if (cnt != k)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		cout << s[0];
		int i = 1;
		while (i < (int)s.length() and !start[i])
		{
			cout << s[i];
			i++;
		}
		for (; i < (int) s.length(); i++)
		{
			if (start[i])
				cout << "\n";
			cout << s[i];
		}
	}
	return 0;
}
