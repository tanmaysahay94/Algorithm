#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL inf = 1e6 + 10;
VLL fen((int) inf, 0);

void add(LL idx, LL val)
{
	idx++;
	while (idx < inf)
	{
		fen[idx] += val;
		idx += idx&-idx;
	}
}

LL get(LL idx)
{
	LL ret = 0;
	while (idx > 0)
	{
		ret += fen[idx];
		idx -= idx&-idx;
	}
	return ret;
}

LL sum(LL x, LL y)
{
	return get(y) - get(x);
}

int main()
{
	LL n;
	cin >> n;
	VI v(n);
	LL tot[n + 10];
	for (LL i = 0; i < n; i++)
	{
		cin >> v[i];
		tot[i] = v[i];
	}
	sort(tot, tot + n);
	LL sz = unique(tot, tot + n) - tot;
	for (LL i = 0; i < n; i++)
		v[i] = lower_bound(tot, tot + sz, v[i]) - tot;
	VLL cnt((int) inf, 0), rem((int) inf);
	for (int i = n - 1; i >= 0; i--)
	{
		cnt[v[i]]++;
		add(cnt[v[i]], 1LL);
		rem[i] = cnt[v[i]];
	}
	for (int i = 0; i < inf; i++)
		cnt[i] = 0;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		add(rem[i], -1);
		cnt[v[i]]++;
		ans += sum(1LL, cnt[v[i]]);
	}
	cout << ans << endl;
	return 0;
}
