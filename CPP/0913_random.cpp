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
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'A' and s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		if (s[i] == 'y' or s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
			continue;
		cout << "." << s[i];
	}
	return 0;
}
