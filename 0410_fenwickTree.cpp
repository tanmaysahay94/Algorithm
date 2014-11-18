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

// 0-indexed fenwickTree
// range update range query not implemented yet
class fenwickTree {
	VLL tree;
	LL n;
	public:
		fenwickTree(LL N): n(N) {
			LL val;
			tree.resize(n + 10, 0);
			for (LL i = 0; i < n; i++) {
				SLL(val);
				update(i, val);
			}
		}
		void update(LL idx, LL val) {
			idx += 2;
			LL lim = sz(tree);
			while (idx < lim) {
				tree[idx] += val;
				idx += (idx&-idx);
			}
		}
		void update(LL l, LL r, LL val) {
			if (l > r)
				swap(l, r);
			update(l, val);
			update(r + 1, -val);
		}
		LL getSum(LL idx) {
			LL ret = 0;
			idx += 2;
			while (idx) {
				ret += tree[idx];
				idx -= (idx&-idx);
			}
			return ret;
		}
		LL sum(LL l, LL r) {
			if (l > r)
				swap(l, r);
			return getSum(r) - getSum(l - 1);
		}
		LL sum(LL idx) {
			idx += 2;
			LL ret = tree[idx];
			if (idx) {
				LL z = idx - (idx&-idx);
				idx--;
				while (idx != z) {
					ret -= tree[idx];
					idx -= (idx&-idx);
				}
			}
			return ret;
		}
};

int main()
{
	LL n, q;
	SLL(n); SLL(q);
	// n is the size of the array that uses the fenwickTree
	// fenwickTree is 0-indexed
	fenwickTree f(n);
	while (q--)
	{
		LL type, x, y;
		cout << "1. Pt Update\n2. Range Update\n3. Range Query\n4. Pt Query\n";
		SLL(type); SLL(x);
		if (type == 3)
		{
			SLL(y);
			printf("%lld\n", f.sum(x, y));
		}
		else if (type == 1)
		{
			SLL(y);
			f.update(x, y);
		}
		else if (type == 2)
		{
			LL val;
			SLL(y); SLL(val);
			f.update(x, y, val);
		}
		else
			printf("%lld\n", f.sum(x));
	}
	return 0;
}
