#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();
	if (m > n)
		swap(s1, s2), swap(m, n);
	int ans = 0;
	for (int len = 1; len <= min(m, n); len++)
	{
		bool yes = true;
		if (m % len or n % len)
			continue;
		for (int i = 0; i < m and yes; i++)
			if (s1[i] != s1[i % len])
				yes = false;
		for (int i = 0; i < n and yes; i++)
			if (s2[i] != s2[i % len])
				yes = false;
		for (int i = 0; i < len and yes; i++)
			if (s1[i] != s2[i])
				yes = false;
		ans += yes;
	}
	cout << ans;
	return 0;
}
