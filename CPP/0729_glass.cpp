#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void upd(set<long long>& a, set<pair<long long, pair<long long, long long> > >& al, long long v)
{
	a.insert(v);
	set<long long>::iterator sit = a.find(v);
	sit--;
	long long lower = *sit;
	sit++; sit++;
	long long upper = *sit;
	set<pair<long long, pair<long long, long long> > >::iterator spit = al.find(make_pair(upper - lower, make_pair(lower, upper)));
	al.erase(spit);
	al.insert(make_pair(v - lower, make_pair(lower, v)));
	al.insert(make_pair(upper - v, make_pair(v, upper)));
}

int main()
{
	optimizeIO();
	long long w, h, n;
	cin >> w >> h >> n;
	set<long long> a, b;
	set<pair<long long, pair<long long, long long> > > al, bl;
	a.insert(0); a.insert(w);
	b.insert(0); b.insert(h);
	al.insert(make_pair(w, make_pair(0, w)));
	bl.insert(make_pair(h, make_pair(0, h)));
	for (long long i = 0; i < n; i++)
	{
		string type;
		long long v;
		cin >> type >> v;
		if (type[0] == 'V')
			upd(a, al, v);
		else if (type[0] == 'H')
			upd(b, bl, v);
		long long x, y;
		x = (*(al.rbegin())).first;
		y = (*(bl.rbegin())).first;
		cout << x * y << endl;
	}
	return 0;
}
