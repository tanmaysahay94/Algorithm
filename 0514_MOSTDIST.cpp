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

priority_queue<pair<LL, pair<LL, LL> > > h1, h2, h3, h4;
vector<pair<pair<LL, LL>, bool> > pts;
map<pair<LL, LL>, LL> ptIdx;

LL max4(LL a, LL b, LL c, LL d)
{
	return max(a, max(b, max(c, d)));
}

LL f1(LL a, LL b)
{
	return a + b;
}
LL f2(LL a, LL b)
{
	return a - b;
}
LL f3(LL a, LL b)
{
	return -a + b;
}
LL f4(LL a, LL b)
{
	return -a - b;
}

pair<LL, LL> getmax(priority_queue<pair<LL, pair<LL, LL> > >& h)
{
	pair<LL, pair<LL, LL> > tmp = h.top();
	while (not pts[ptIdx[tmp.s]].s)
	{
		h.pop();
		tmp = h.top();
	}
	return tmp.s;
}

int main()
{
	LL q, x, y, ans = 0, count = 0;
	SLL(q);
	while (q--)
	{
		getchar();
		char qType;
		scanf("%c", &qType);
		if (qType == '+')
		{
			SLL(x); SLL(y);
			x = x ^ ans;
			y = y ^ ans;
			pair<LL, LL> tmp = mp(x, y);
			pts.pb(mp(tmp, true));
			ptIdx[tmp] = count++;
			h1.push(mp(f1(x, y), tmp));
			h2.push(mp(f2(x, y), tmp));
			h3.push(mp(f3(x, y), tmp));
			h4.push(mp(f4(x, y), tmp));
		}
		else if (qType == '-')
		{
			SLL(x);
			x = x ^ ans;
			pts[x - 1].s = false;
		}
		else
		{
			SLL(x); SLL(y);
			x = x ^ ans;
			y = y ^ ans;
			pair<LL, LL> a = getmax(h1);
			pair<LL, LL> b = getmax(h2);
			pair<LL, LL> c = getmax(h3);
			pair<LL, LL> d = getmax(h4);
			LL aa = f1(a.f, a.s);
			LL bb = f2(b.f, b.s);
			LL cc = f3(c.f, c.s);
			LL dd = f4(d.f, d.s);
			ans = max4(f1(x, y) + dd, f2(x, y) + cc, f3(x, y) + bb, f4(x, y) + aa);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
