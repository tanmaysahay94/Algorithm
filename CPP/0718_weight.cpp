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
	map<char, int> mp;
	mp['Q'] = mp['q'] = 9;
	mp['R'] = mp['r'] = 5;
	mp['B'] = mp['b'] = 3;
	mp['N'] = mp['n'] = 3;
	mp['P'] = mp['p'] = 1;
	int w(0), b(0);
	string str;
	for (int i = 0; i < 8; i++)
	{
		cin >> str;
		for (int i = 0; str[i]; i++)
			if (str[i] >= 'A' and str[i] <= 'Z')
				w += mp[str[i]];
			else if (str[i] >= 'a' and str[i] <= 'z')
				b += mp[str[i]];
	}
	if (w > b)
		cout <<"White\n";
	else if (w < b)
		cout << "Black\n";
	else
		cout <<"Draw\n";
	return 0;
}
