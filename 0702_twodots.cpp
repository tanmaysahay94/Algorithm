#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n, m;

bool dfs(int r, int c, vector<string>& mp, int depth, set<pair<int, int> >&pr, int fi, int fj)
{
	char curr = mp[r][c];
	set<pair<int, int> > possible;
	pr.insert(make_pair(r, c));
	if (r - 1 >= 0)
		if (mp[r - 1][c] == curr)
			possible.insert(make_pair(r - 1, c));
	if (r + 1 < n)
		if (mp[r + 1][c] == curr)
			possible.insert(make_pair(r + 1, c));
	if (c -1 >= 0)
		if (mp[r][c - 1] == curr)
			possible.insert(make_pair(r, c - 1));
	if (c + 1 < m)
		if (mp[r][c + 1] == curr)
			possible.insert(make_pair(r, c + 1));
	if (possible.size() == 0)
		return false;
	set<pair<int, int> >::iterator it;
	bool ret = false;
	for (it = possible.begin(); it != possible.end(); it++)
		if (pr.count(make_pair((*it).first, (*it).second)) == 0)
			ret = ret or dfs((*it).first, (*it).second, mp, depth + 1, pr, r, c);
		else if (depth >= 3 and not ((*it).first == fi and (*it).second == fj) and not (r == fi and c == fj))
			ret = true;
	return ret;
}

int main()
{
	optimizeIO();
	bool found = false;
	cin >> n >> m;
	vector<string> mp(n);
	set<pair<int, int> > pr;
	for (int i = 0; i < n; i++)
		cin >> mp[i];
	for (int i = 0; i < n and not found; i++)
		for (int j = 0; j < m and not found; j++, pr.clear())
			if (dfs(i, j, mp, 0, pr, 0, 0))
				found = true;
	if (found)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
