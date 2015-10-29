#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<string> > &ret, vector<string> &tmp, vector<vector<string> > &v, int start, int n)
{
	if (start == n)
	{
		ret.push_back(tmp);
		return;
	}
	for (auto word: v[start])
	{
		tmp.push_back(word);
		solve(ret, tmp, v, start + 1, n);
		tmp.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<string> > v(n);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			string word;
			cin >> word;
			v[i].push_back(word);
		}
	}
	vector<vector<string> > ret;
	vector<string> tmp;
	solve(ret, tmp, v, 0, n);
	for (auto row: ret)
	{
		for (auto word: row)
			cout << word << " ";
		cout << endl;
	}
	return 0;
}
