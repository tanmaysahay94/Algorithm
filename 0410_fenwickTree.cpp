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

class fenwickTree {
	VLL v, tree;
	public:
		fenwickTree(VLL V): v(V) {
			initializeFenwickTree();
		}
		void initializeFenwickTree() {
			LL lim = v.size();
			tree.resize(lim);
			for (LL i = 0; i < lim; i++)
				increase(i, v[i]);
		}
		void increase(LL i, LL val) {
			LL lim = sz(tree);
			for (; i < lim; i |= i + 1)
				tree[i] += val;
		}
		LL getSum(LL left, LL right) {			// left and right are 0-indexed indices
			return sum(right) - sum(left - 1);
		}
		LL sum(LL idx) {						// idx is a 0-indexed index
			LL ret = 0;
			while (idx >= 0) {
				ret += tree[idx];
				idx &= idx + 1;
				idx--;
			}
			return ret;
		}
};

int main()
{
	LL n;
	SLL(n);
	VLL v(n);
	for (LL i = 0; i < n; i++)
		SLL(v[i]);
	fenwickTree ft(v);
	LL q, l, r, qType;
	SLL(q);
	while (q--)
	{
		// qType = 0 is to increase the value at index l by a value r
		// qType = 1 is to get the sum of all values in range [l, r]
		SLL(qType); SLL(l); SLL(r);
		if (qType == 1)
			cout << ft.getSum(l, r) << endl;
		else
			ft.increase(l, r);
	}
	return 0;
}
