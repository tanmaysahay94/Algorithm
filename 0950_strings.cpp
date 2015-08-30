#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string f(int n)
{
	string ret;
	while (n)
	{
		ret.push_back(n%10 + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s.size() <= 10)
			cout << s << endl;
		else
		{
			string a;
			a.push_back(s[0]);
			string foo = f((int)(s.size() - 2));
			a += foo;
			a.push_back(s[(int) (s.size() - 1)]);
			cout << a << endl;
		}
	}
	return 0;
}
