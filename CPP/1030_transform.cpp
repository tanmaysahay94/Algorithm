#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> to(26);
	for (int i = 0; i < 26; i++)
		to[i] = i;
	for (int i = 0; i < m; i++)
	{
		char p, q;
		cin >> p >> q;
		p -= 'a';
		q -= 'a';
		for (int j = 0; j < 26; j++)
			if (to[j] == p)
				to[j] = q;
			else if (to[j] == q)
				to[j] = p;
	}
	for (int i = 0; i < (int) s.size(); i++)
		s[i] = to[s[i] - 'a'] + 'a';
	cout << s;
	return 0;
}
