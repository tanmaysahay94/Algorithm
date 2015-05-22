#include <bits/stdc++.h>

using namespace std;

struct tree
{
	int open, close;
} st[65536];

char b[32768];

inline void flip(char& c)
{
	if (c == '(') c = ')';
	else if (c == ')') c = '(';
}

void setleaf(tree& tmp, char& c)
{
	if (c == '(') tmp.open = 1, tmp.close = 0;
	else tmp.open = 0, tmp.close = 1;
}

void merge(tree& tmp, tree& foo, tree& bar)
{
	int merged = min(foo.open, bar.close);
	tmp.open = foo.open + bar.open - merged;
	tmp.close = foo.close + bar.close - merged;
}

void build(int z, int i, int j)
{
	if (i == j)
	{
		setleaf(st[z], b[i]);
		return;
	}
	int m = (i + j) / 2, l = 2 * z, r = 2 * z + 1;
	build(l, i, m);
	build(r, m + 1, j);
	merge(st[z], st[l], st[r]);
}

void update(int z, int q, int i, int j)
{
	if (q == i and i == j)
	{
		setleaf(st[z], b[q]);
		return;
	}
	int m = (i + j) / 2, l = 2 * z, r = 2 * z + 1;
	if (q <= m) update(l, q, i, m);
	else update(r, q, m + 1, j);
	merge(st[z], st[l], st[r]);
}

int main()
{
	int n, m, q, i = 1;
	while (scanf("%d", &n) == 1)
	{
		printf("Test %d:\n", i++);
		scanf("%s%d", b, &m);
		build(1, 0, n - 1);
		while (m--)
		{
			scanf("%d", &q);
			if (!q)
			{
				if (st[1].open == 0 and st[1].close == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				flip(b[--q]);
				update(1, q, 0, n - 1);
			}
		}
	}
	return 0;
}
