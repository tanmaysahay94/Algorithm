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
	cin >> str;
	int a(0), b(0);
	for (int i = 0; str[i]; i++)
		if (str[i] == 'x')
			a++;
		else
			b++;
	int change = abs(a - b)/2;
	cout << change << endl;
	if (a > b)
		for (int i = 0; str[i] and change; i++)
		{
			if (str[i] == 'x')
			{
				str[i] = 'X';
				change--;
			}
		}
	else
		for (int i = 0; str[i] and change; i++)
			if (str[i] == 'X')
			{
				str[i] = 'x';
				change--;
			}
	cout << str << endl;
	return 0;
}
