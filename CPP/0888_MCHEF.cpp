#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int inf = INT_MAX;
vector<LL> A(1e5 + 5);
vector<int> leastCost(1e5 + 5);
vector<int> T(4e5 + 5);
vector<int> L(4e5 + 5);
LL knpsk[2][555];

void build(int v, int s, int e)
{
	if (s > e)
		return;
	if (s == e)
	{
		T[v] = inf;
		L[v] = inf;
		return;
	}
	int m = (s + e) / 2;
	build(2 * v, s, m);
	build(2*v+1,m+1,e);
	T[v] = max(T[2*v], T[2*v+1]);
	L[v] = max(L[2*v], L[2*v+1]);
}

void update(int v, int rs, int re, int x, int y, int c)
{
	if (L[v] != inf)
	{
		T[v] = min(T[v], L[v]);
		if (rs != re)
		{
			L[2*v] = min(L[2*v], L[v]);
			L[2*v+1] = min(L[2*v+1], L[v]);
		}
		L[v] = inf;
	}
	if (rs > re or rs > y or re < x)
		return;
	if (x <= rs and re <= y)
	{
		T[v] = min(T[v], c);
		if (rs != re)
		{
			L[2*v] = min(L[2*v], c);
			L[2*v+1] = min(L[2*v+1], c);
		}
		return;
	}
	int m = (rs + re) / 2;
	update(2 * v, rs, m, x, y, c);
	update(2*v+1, m+1,re,x, y, c);
}

int query(int v, int rs, int re, int i)
{
	if (L[v] != inf)
	{
		T[v] = min(T[v], L[v]);
		if (rs != re)
		{
			L[2*v] = min(L[2*v], L[v]);
			L[2*v+1] = min(L[2*v+1], L[v]);
		}
		L[v] = inf;
	}
	if (rs > re or rs > i or re < i)
		return inf;
	if (rs >= i and i >= re)
		return T[v];
	int m = (rs + re) / 2;
	LL foo = query(2 * v, rs, m, i);
	LL bar = query(2*v+1, m + 1, re, i);
	return min(foo, bar);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k, m;
		int l, r, c;
		scanf("%d%d%d", &n, &k, &m);
		LL score = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &A[i]);
			score += A[i];
		}
		build(1, 1, n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &l, &r, &c);
			update(1, 1, n, l, r, (LL) c);
		}
		for (int i = 1; i <= n; i++)
			if (A[i] < 0)
				leastCost[i] = query(1, 1, n, i);
			else
				leastCost[i] = inf;
		memset(knpsk, 0, sizeof(knpsk));
		for (int i = 1; i <=n; i++)
			A[i] = -A[i];
		int row = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				if (A[i] < 0)
					knpsk[row][j] = knpsk[row ^ 1][j];
				else
				{
					knpsk[row][j] = knpsk[row ^ 1][j];
					if (j >= leastCost[i])
						knpsk[row][j] = max(knpsk[row][j], knpsk[row ^ 1][j - leastCost[i]] + A[i]);
				}
			}
			row ^= 1;
		}
		printf("%lld\n", score + knpsk[row ^ 1][k]);
	}
	return 0;
}
