#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 5e5 + 5;
int n;

LL tree[maxn], v[maxn];

LL read(int idx)
{
	LL sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, LL val)
{
	while (idx <= maxn)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

LL f()
{
	LL cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		LL tmp = read(v[i] - 1);
		cnt += tmp;
		update(v[i], 1);
	}
	return cnt;
}

bool isSorted()
{
	for (int i = 1; i < n; i++)
		if (v[i] < v[i - 1])
			return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	if (isSorted())
	{
		printf("Cool Array");
		return 0;
	}
	memset(tree, 0, sizeof(tree));
	int inv_count = f();
	int l, r;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] >= v[i])
				continue;
			memset(tree, 0, sizeof(tree));
			swap(v[i], v[j]);
			int tmp = f();
			if (tmp < inv_count)
				l = i + 1, r = j + 1, inv_count = tmp;
			else if (tmp == inv_count)
				if (i + 1 < l or (i + 1 == l and j + 1 < r))
					l = i + 1, r = j + 1;
			swap(v[i], v[j]);
		}
	printf("%d %d\n", l, r);
	return 0;
}
