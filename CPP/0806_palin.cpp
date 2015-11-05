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
	int k;
	cin >> s >> k;
	int l = s.length();
	if (l % k)
	{
		cout << "NO\n";
		return 0;
	}
	l /= k;
	int a = 1;
	for (int i = 0; a and i < l * k; i += l)
		for (int j = i, k = i + l - 1; a and j < i + l and k >= i; j++, k--)
			if (s[j] != s[k])
				a = 0;
	if (a)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
