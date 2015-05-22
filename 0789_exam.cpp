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
	if (n == 1 or n == 2)
	{
		cout << "1\n1\n"; return 0;
	}
	if (n == 3)
	{
		cout << "2\n1 3\n"; return 0;
	}
	if (n == 4)
	{
		cout << "4\n2 4 1 3\n"; return 0;
	}
	vector<int> v(n);
	for (int i = 0, j = 1; i < n/2 + (n & 1); i++, j++)
		v[i] = 2 * j - 1;
	for (int i = n/2 + (n & 1), j = 1; i < n; i++, j++)
		v[i] = 2 * j;
	vector<int> ans;
	ans.push_back(v[0]);
	for (int i = 1; i < (int) v.size(); i++)
		if (abs(v[i] - v[i - 1]) != 1)
			ans.push_back(v[i]);
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
