#include <bits/stdc++.h>

using namespace std;

string s;
int m;
vector<int> ans;

void solve(int diff, int prev, int iter, bool& found)
{
	if (found)
		return;
	if (iter == m + 1)
	{
		ans.push_back(prev);
		found = true;
		return;
	}
	for (int i = 1; i <= 10; i++)
		if (s[i] == '1' and i != prev and (i - diff > 0))
			solve(i - diff, i, iter + 1, found);
	if (found)
		ans.push_back(prev);
}

int main()
{
	s.push_back('$');
	for (int i = 0; i < 10; i++)
	{
		char c;
		cin >> c;
		s.push_back(c);
	}
	cin >> m;
	bool found = 0;
	solve(0, 0, 1, found);
	reverse(ans.begin(), ans.end());
	if (found)
	{
		cout << "YES\n";
		for (int i = 1; i < (int) ans.size(); i++)
			cout << ans[i] << ' ';
	}
	else
		cout << "NO\n";
	return 0;
}
