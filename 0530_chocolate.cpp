#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

vector<pair<LL, pair<pair<LL, LL>, pair<LL, LL> > > > answer;
map<pair<pair<LL, LL>, pair<LL, LL> >, int> mp;

void choc(LL ax, LL ay, LL bx, LL by, LL m)
{
	pair<pair<LL, LL>, pair<LL, LL> > tmp1 = mp(mp(ax, ay), mp(bx, by));
	pair<pair<LL, LL>, pair<LL, LL> > tmp2 = mp(mp(ax, ay), mp(by, bx));
	pair<pair<LL, LL>, pair<LL, LL> > tmp3 = mp(mp(ay, ax), mp(bx, by));
	pair<pair<LL, LL>, pair<LL, LL> > tmp4 = mp(mp(ay, ax), mp(by, bx));
	if (mp.find(tmp1) != mp.end() or mp.find(tmp2) != mp.end() or mp.find(tmp3) != mp.end() or mp.find(tmp4) != mp.end())
		return;
	else
		mp[tmp4] = mp[tmp3] = mp[tmp2] = mp[tmp1] = 1;
	LL a = ax * ay;
	LL b = bx * by;
	if (a == b)
	{
		answer.pb(mp(m, tmp1));
		return;
	}
	if (a > b)
	{
		if (ax%2 and ax%3 and ay%2 and ay%3)
			return;
		if (ax % 2 == 0)
			choc(ax/2, ay, bx, by, m+1);
		if (ax % 3 == 0)
			choc(2*ax/3, ay, bx, by, m+1);
		if (ay % 2 == 0)
			choc(ax, ay/2, bx, by, m+1);
		if (ay % 3 == 0)
			choc(ax, 2*ay/3, bx, by, m+1);
	}
	else
	{
		if (bx%2 and bx%3 and by%2 and by%3)
			return;
		if (bx % 2 == 0)
			choc(ax, ay, bx/2, by, m+1);
		if (bx % 3 == 0)
			choc(ax, ay, 2*bx/3, by, m+1);
		if (by % 2 == 0)
			choc(ax, ay, bx, by/2, m+1);
		if (by % 3 == 0)
			choc(ax, ay, bx, 2*by/3, m+1);
	}
}

int main()
{
	LL ax, ay, bx, by;
	SLL(ax); SLL(ay); SLL(bx); SLL(by);
	choc(ax, ay, bx, by, 0);
	if (answer.size() == 0)
		printf("-1\n");
	else
	{
		sortv(answer);
		printf("%lld\n%lld %lld\n%lld %lld\n", answer[0].f, answer[0].s.f.f, answer[0].s.f.s, answer[0].s.s.f, answer[0].s.s.s);
	}
	return 0;
}
