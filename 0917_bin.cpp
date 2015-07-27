#include <bits/stdc++.h>

using namespace std;

string s;

void add(int i)
{
	int carry = 1;
	while (i < (int) s.size())
	{
		if (carry == 0)
			break;
		if (s[i] == '0')
		{
			s[i] = '1', carry = 0;
			break;
		}
		else
		{
			s[i] = '0', carry = 1;
			i++;
		}
	}
	if (i == (int) s.size() and carry)
		s.push_back('1');
}

int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	int ans = 0;
	int i = 0;
	while (i + 1 < (int) s.size())
	{
		if (s[i] == '0')
			i++;
		else
			add(i);
		ans++;
	}
	cout << ans;
	return 0;
}
