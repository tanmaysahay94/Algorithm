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

class segmentTree {
	LL n, identity, depth, size;
	VLL st;
	LL function(LL a, LL b) {
		return a + b;
	}
	void update(LL node, LL ss, LL se, LL start, LL end, LL val) {
		if (ss > se || ss > end || se < start)
			return;
		if (ss == se) {
			st[node] += val;
			return;
		}
		update(2*node, ss, (ss+se)/2, start, end, val);
		update(2*node+1, 1+(ss+se)/2, se, start, end, val);
		st[node] = function(st[2*node], st[2*node+1]);
	}
	LL get(LL node, LL ss, LL se, LL start, LL end) {
		if (ss > se || ss > end || se < start)
			return identity;
		if (ss >= start and se <= end)
			return st[node];
		LL a = get(2*node, ss, (ss+se)/2, start, end);
		LL b = get(2*node+1, 1+(ss+se)/2, se, start, end);
		return function(a, b);
	}
	public:
	segmentTree(LL N): n(N) {
		identity = 0;
		depth = ceil(log2(n));
		size = 1<<(depth+1);
		st.resize(size);
		for (LL i = 0; i < size; i++)
			st[i] = identity;
	}
	void update(LL start, LL end, LL val) {
		update(1, 0, n - 1, start, end, val);
	}
	LL get(LL start, LL end) {
		return get(1, 0, n - 1, start, end);
	}
};

int main()
{
	LL t, n, c, type, p, q, v;
	SLL(t);
	while (t--)
	{
		SLL(n); SLL(c);
		segmentTree st(n);
		while (c--)
		{
			SLL(type); SLL(p); SLL(q);
			p--; q--;
			if (!type)
			{
				SLL(v);
				st.update(p, q, v);
			}
			else
				printf("%lld\n", st.get(p, q));
		}
	}
	return 0;
}
