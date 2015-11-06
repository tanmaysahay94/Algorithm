#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	vector<int> o(n);
	for (int i = 0; i < n; i++)
	{
		cin >> o[i];
		o[i]--;
	}
	reverse(o.begin(), o.end());
	vector<vector<int> > u = v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			u[i][j] = v[o[i]][o[j]];
	vector<LL> ans;
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				u[i][j] = min(u[i][j], u[i][l] + u[l][j]);
		LL sum = 0;
		for (int i = 0; i <= l; i++)
			for (int j = 0; j <= l; j++)
				sum += u[i][j];
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	for (auto a: ans)
		cout << a << ' ';
	return 0;
}
