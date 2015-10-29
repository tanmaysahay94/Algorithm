#include <bits/stdc++.h>

using namespace std;

void solve(vector<string>& ret, string& tmp, map<int, string>& mp, vector<int>& array, int idx, int lim)
{
	if (idx == lim)
	{
		ret.push_back(tmp);
		return;
	}
	string word = mp[array[idx]];
	for (auto w: word)
	{
		tmp.push_back(w);
		solve(ret, tmp, mp, array, idx + 1, lim);
		tmp.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;
	map<int, string> mp;
	for (int i = 0; i < n; i++)
	{
		int num;
		string word;
		cin >> num >> word;
		mp[num] = word;
	}
	vector<int> array(n);
	for (int i = 0; i < n; i++)
		cin >> array[i];
	vector<string> ret;
	string tmp = "";
	solve(ret, tmp, mp, array, 0, n);
	for (auto r: ret)
		cout << r << endl;
	return 0;
}
