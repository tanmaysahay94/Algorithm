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
	string str;
	int v[26] = {0};
	cin >> str;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' and str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		v[str[i] - 'a']++;
	}
	bool yes = true;
	for (int i = 0; i < 26 and yes; i++)
		if (v[i] == 0)
			yes = false;
	if (yes) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
