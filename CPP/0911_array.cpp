#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct cmp
{
	bool operator() (const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b)
	{
		if (a.first != b.first)
			return a.first < b.first;
		return a.second.second - a.second.first > b.second.second - b.second.first;
	}
};

map<int, vector<int> > mp;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, cmp> pq;

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		if (mp.count(val) == 0)
		{
			vector<int> v(3);
			v[0] = 1;
			v[1] = v[2] = i;
			mp[val] = v;
		}
		else
		{
			vector<int> v = mp[val];
			v[0]++;
			v[2] = i;
			mp[val] = v;
		}
	}
	for (auto m: mp)
		pq.push(make_pair(m.second[0], make_pair(m.second[1], m.second[2])));
	cout << (pq.top()).second.first << ' ' << (pq.top()).second.second;
	return 0;
}
