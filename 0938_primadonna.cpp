#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		int n;
		string s;
		cin >> n >> s;
		int standing = s[0] - '0';
		int req = 0;
		for (int shyLevel = 1; shyLevel < (int) s.size(); shyLevel++)
		{
			if (standing < shyLevel)
			{
				req += shyLevel - standing;
				standing = shyLevel;
			}
			standing += s[shyLevel] - '0';
		}
		cout << "Case #"<<T<<": "<<req << '\n';
	}
	return 0;
}
