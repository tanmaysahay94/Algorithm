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
#define LSOne(val) (val&(-val))
#define f first
#define s second

class fenwickTreeRange {
	LL n;
	VLL bit1, bit2;
	public:
	void clean(VLL& bit, LL size) {
		bit.resize(size);
		for (LL i = 0; i < size; i++)
			bit[i] = 0;
	}
	void update(VLL& bit, LL idx, LL val) {
		for (; idx <= n; idx += LSOne(idx))
			bit[idx] += val;
	}
	void rangeUpdate(LL p, LL q, LL val) {
		update(bit1, p, val);
		update(bit1, q + 1, -val);
		update(bit2, p, val * (p - 1));
		update(bit2, q + 1, -val * q);
	}
	LL query(VLL& bit, LL idx) {
		LL ans = 0;
		for (; idx; idx -= LSOne(idx))
			ans += bit[idx];
		return ans;
	}
	LL query(LL idx) {
		return idx * query(bit1, idx) - query(bit2, idx);
	}
	LL rangeQuery(LL p, LL q) {
		return query(q) - query(p - 1);
	}
	fenwickTreeRange(LL N): n(N) {
		clean(bit1, n + 1);
		clean(bit2, n + 1);
	}
};

int main()
{
	LL n, t, c, type, p, q, v;
	SLL(t);
	while (t--)
	{
		SLL(n); SLL(c);
		fenwickTreeRange f(n);
		while (c--)
		{
			SLL(type); SLL(p); SLL(q);
			if (!type)
			{
				SLL(v);
				f.rangeUpdate(p, q, v);
			}
			else
				printf("%lld\n", f.rangeQuery(p, q));
		}
	}
	return 0;
}
