#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	while (t--)
	{
		int ans1 = 0, ans2 = 0;
		cin >> s;
		for (int i = 0; s[i]; i++)
		{
			if (i&1)
				if (s[i] == '+')
					ans1++;
				else
					ans2++;
			else
				if (s[i] == '-')
					ans1++;
				else
					ans2++;
		}
		cout << min(ans1, ans2) << endl;
	}
	return 0;
}
