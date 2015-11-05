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
	string s, t;
	cin >> s >> t;
	map<char, int> needle, haystack;
	for (int i = 0; s[i]; i++)
		needle[s[i]]++;
	for (int i = 0; t[i]; i++)
		haystack[t[i]]++;
	int yay(0), whoops(0);
	map<char, int>::iterator it;
	for (it = needle.begin(); it != needle.end(); it++)
	{
		char c = (*it).first;
		int ned = needle[c];
		int hay = haystack[c];
		yay += min(ned, hay);
		needle[c] -= min(ned, hay);
		haystack[c] -= min(ned, hay);
	}
	for (it = needle.begin(); it != needle.end(); it++)
	{
		char c = (*it).first;
		char opp;
		if (c >= 'A' and c <= 'Z')
			opp = c - 'A' + 'a';
		else if (c >= 'a' and c <= 'z')
			opp = c - 'a' + 'A';
		int ned = needle[c];
		int hay = haystack[opp];
		whoops += min(ned, hay);
		needle[c] -= min(ned, hay);
		haystack[opp] -= min(ned, hay);
	}
	cout << yay << ' ' << whoops << endl;
	return 0;
}
