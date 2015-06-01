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
	set<pair<int, int> > s;
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int> > v(n, vector<int> (m));
	vector<int> vv(n);
	for (int i = 0; i < n; i++)
	{
		int ans(0), curr(0);
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j])
				curr++;
			else
			{
				ans = max(ans, curr);
				curr = 0;
			}
		}
		ans = max(ans, curr);
		s.insert(make_pair(ans, i));
		vv[i] = ans;
	}
	for (int i = 0; i < q; i++)
	{
		int p, q;
		cin >> p >> q;
		p--; q--;
		v[p][q] ^= 1;
		s.erase(s.find(make_pair(vv[p], p)));
		int ans(0), curr(0);
		for (int j = 0; j < m; j++)
			if (v[p][j])
				curr++;
			else
			{
				ans = max(curr, ans);
				curr = 0;
			}
		ans = max(ans, curr);
		s.insert(make_pair(ans, p));
		vv[p] = ans;
		cout << (*(s.rbegin())).first << endl;
	}
	return 0;
}
