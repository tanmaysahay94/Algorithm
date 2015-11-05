#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int happy(0), sad(0);
	for (int i = 1; i < (int) s.size(); i++)
	{
		char b = s[i];
		char a = s[i - 1];
		if ((a == ':' and b == ')') or (a == '(' and b == ':')) happy++;
		if ((a == ':' and b == '(') or (a == ')' and b == ':')) sad++;
	}
	if (happy > sad) cout << "HAPPY";
	else if (happy == sad) cout << "BORED";
	else cout << "SAD";
	return 0;
}
