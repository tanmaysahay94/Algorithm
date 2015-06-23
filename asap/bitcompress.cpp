#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m, lim;
const LL minval = 0;

vector<LL> ft(lim + 10, 0);

void update(LL idx, LL increment)
{
	LL s = ft.size();
	while (idx < s)
	{
		ft[idx] += increment;
		idx += (idx & -idx);
	}
}

LL query(LL idx)
{
	LL ret = 0;
	while (idx)
	{
		ret += ft[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	vector<pair<char, LL> > v(m);
	set<LL> bar;
	bar.insert(minval);
	for (int i = 0; i < m; i++)
	{
		getchar();
		char c;
		LL foo;
		scanf("%c%lld", &c, &foo);
		v[i] = make_pair(c, foo);
		bar.insert(foo);
	}
	vector<LL> buz;
	for (set<LL>::iterator it = bar.begin(); it != bar.end(); it++)
		buz.push_back(*it);
	map<LL, LL> mp;
	for (int i = 0; i < m; i++)
	{
		LL foo = v[i].second;
		mp[foo] = lower_bound(buz.begin(), buz.end(), foo) - buz.begin();
	}
	mp[minval] = lower_bound(buz.begin(), buz.end(), minval) - buz.begin();
	lim = mp.size();
	for (int i = 0; i < m; i++)
		if (v[i].first == 'D')
			update(mp[v[i].second], 1);
		else
			printf("%lld\n", v[i].second + query(mp[v[i].second]));
	return 0;
}
