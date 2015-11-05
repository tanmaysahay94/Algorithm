#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

struct tree
{
	int maxv, cnt;
};

int a[maxn + 1];
tree st[4 * maxn + 1];

void merge(tree& a, tree& b, tree& c)
{
	if (b.maxv == c.maxv)
		a.maxv = b.maxv, a.cnt = b.cnt + c.cnt;
	else if (b.maxv > c.maxv)
		a.maxv = b.maxv, a.cnt = b.cnt;
	else
		a.maxv = c.maxv, a.cnt = c.cnt;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].maxv = a[i];
		st[idx].cnt = 1;
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

int main()
{
	tree T;
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	build(1, 0, n - 1);
//	for (int i = 1; i < 9; i++)
//		printf("%d: maxv %d cnt %d\n", i, st[i].maxv, st[i].cnt);
	while (m--)
	{
		scanf("%d%d", &x, &y);
		query(T, 1, --x, --y, 0, n - 1);
		printf("%d\n", T.cnt);
	}
	return 0;
}
