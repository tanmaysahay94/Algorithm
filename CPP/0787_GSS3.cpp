#include <bits/stdc++.h>

using namespace std;

const int maxn = 7e4;

struct tree
{
	int maxv, lval, rval, sum;
};

int a[maxn + 1];
tree st[4 * maxn + 1];

void merge(tree& a, tree& b, tree& c)
{
	a.sum = b.sum + c.sum;
	a.lval = max(b.lval, b.sum + c.lval);
	a.rval = max(c.rval, c.sum + b.rval);
	a.maxv = max(b.maxv, max(c.maxv, b.rval + c.lval));
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].maxv = st[idx].lval = st[idx].rval = st[idx].sum = a[i];
		return;
	}
	int m = (i + j) / 2, l = 2 * idx, r = 2 * idx + 1;
	build(l, i, m);
	build(r, m + 1, j);
	merge(st[idx], st[l], st[r]);
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
	int m = (i + j) / 2, l = 2 * idx, r = 2 * idx + 1;
	if (y <= m)
		query(res, l, x, y, i, m);
	else if (x > m)
		query(res, r, x, y, m + 1, j);
	else
	{
		tree left, right;
		query(left, l, x, m, i, m);
		query(right, r, m + 1, y, m + 1, j);
		merge(res, left, right);
	}
}

void update(int idx, int loc, int val, int i, int j)
{
	if (loc == i and i == j)
	{
		a[loc] = st[idx].sum = st[idx].lval = st[idx].rval = st[idx].maxv = val;
		return;
	}
	int m = (i + j) / 2, l = 2 * idx, r = 2 * idx + 1;
	if (loc <= m)
		update(l, loc, val, i, m);
	else
		update(r, loc, val, m + 1, j);
	merge(st[idx], st[l], st[r]);
}

int main()
{
	tree T;
	int n, m, t, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	build(1, 0, n - 1);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d%d", &t, &x, &y);
		if (t)
		{
			query(T, 1, --x, --y, 0, n - 1);
			printf("%d\n", T.maxv);
		}
		else
			update(1, --x, y, 0, n - 1);
	}
	return 0;
}
