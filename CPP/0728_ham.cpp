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
	int n, ham = 0;
	string s, t;
	cin >> n >> s >> t;
	int map[26][26] = {0};
	for (int i = 0; i < n; i++)
		if (s[i] != t[i])
			ham++, map[s[i] - 'a'][t[i] - 'a'] = i + 1;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (map[i][j] and map[j][i])
			{
				cout << ham - 2 << endl << map[i][j] << ' ' << map[j][i];
				return 0;
			}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (map[i][j])
				for (int k = 0; k < 26; k++)
					if (map[j][k])
					{
						cout << ham - 1 << endl << map[i][j] << ' ' << map[j][k];
						return 0;
					}
	cout << ham << endl << "-1 -1";
	return 0;
}
