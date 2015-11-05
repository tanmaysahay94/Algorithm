#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int s[1001];
	for (int i = 0; i < 1001; i++)
		s[i] = 1;
	s[0] = s[1] = 0;
	for (int i = 2; i < 1001; i++)
		if (s[i])
			for (int j = 2 * i; j < 1001; j += i)
				s[j] = 0;
	vector<int> ans;
	for (int i = 2; i <= n; i++)
		if (s[i])
		{
			int p = i;
			while (p <= n)
			{
				ans.push_back(p);
				p *= i;
			}
		}
	cout << ans.size() << endl;
	for (auto a: ans)
		cout << a << ' ';
	return 0;
}
