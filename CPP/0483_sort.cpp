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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

bool cmpFn(pair<LL, LL> i, pair<LL, LL> j)
{
	if(i.f == j.f)
		return i.s > j.s;
	return i.f < j.f;
}

int main()
{
	vector<pair<LL, LL> > v;
	LL n, a, b;
	SLL(n);
	for (int i = 0; i < n; i++)
	{
		SLL(a); SLL(b);
		v.pb(mp(a, b));
		sort(v.begin(), v.end(), cmpFn);
	}
	for (int i = 0; i < n; i++)
		cout << v[i].f << " " << v[i].s << endl;
	return 0;
}
