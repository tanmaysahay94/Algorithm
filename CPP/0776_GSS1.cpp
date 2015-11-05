#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct tree
{
	long long maxv, sum, lval, rval;
};

const int maxn = 1 << 16;
long long a[maxn];
tree st[maxn <<1];

inline long long max2(long long a, long long b)
{
	return ((a > b) ? a : b);
}

inline long long max3(long long a, long long b, long long c)
{
	return max2(a, max2(b, c));
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].maxv = st[idx].sum = st[idx].lval = st[idx].rval = a[i];
		return;
	}
	int mid = (i + j) / 2;
	int l = 2 * idx;
	int r = l + 1;
	build(l, i, mid);
	build(r, mid + 1, j);
	st[idx].sum = st[l].sum + st[r].sum;
	st[idx].lval = max2(st[l].lval, st[l].sum + st[r].lval);
	st[idx].rval = max2(st[r].rval, st[r].sum + st[l].rval);
	st[idx].maxv = max3(st[l].maxv, st[r].maxv, st[l].rval + st[r].lval);
}

void query(tree& res, int idx, int x, int y, int i, int j)
{
	if (x > y or x > j or y < i)
		return;
	if (x == i and y == j)
	{
		res = st[idx];
		return;
	}
	int m = (i + j) / 2;
	if (y <= m)
		query(res, 2 * idx, x, y, i, m);
	else if (x > m)
		query(res, 2 * idx + 1, x, y, m + 1, j);
	else
	{
		tree left, right;
		query(left, 2 * idx, x, m, i, m);
		query(right, 2 * idx + 1, m + 1, y, m + 1, j);
		res.sum = left.sum + right.sum;
		res.lval = max2(left.lval, left.sum + right.lval);
		res.rval = max2(right.rval, right.sum + left.rval);
		res.maxv = max3(left.maxv, right.maxv, left.rval + right.lval);
	}
}

int main()
{
	tree v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);
	build(1, 0, n - 1);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		query(v, 1, --x, --y, 0, n - 1);
		printf("%lld\n", v.maxv);
	}
	return 0;
}
