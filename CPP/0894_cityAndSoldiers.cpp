#include <bits/stdc++.h>

using namespace std;

#define si(x) scanf("%d", &x)
#define pi(x) printf("%d", x)

const int maxn = 1e5;
const int maxq = 1e5;
const int lim = 1e5 + 1;

int n, q;

vector<int> parent(lim);

void init(int n)
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}

int ancestor(int a)
{
	if (parent[a] != a)
		parent[a] = ancestor(parent[a]);
	return parent[a];
}

void merge(int a, int b)
{
	a = ancestor(a);
	b = ancestor(b);
	if (a != b)
		parent[a] = b;
}

void makeleader(int a)
{
	int pa = ancestor(a);
	parent[pa] = parent[a] = a;
}

int main()
{
	si(n), si(q);

	assert(1 <= n and n <= maxn);
	assert(1 <= q and q <= maxq);

	init(n);

	for (int i = 1; i <= q; i++)
	{
		int type, a, b;

		si(type), si(a);

		assert(1 <= type and type <= 3);
		assert(1 <= a and a <= n);

		if (type == 1)
		{
			si(b);
			assert(1 <= b and b <= n);
			merge(a, b);
		}
		else if (type == 2)
		{
			makeleader(a);
		}
		else if (type == 3)
		{
			pi(ancestor(a));
			puts("");
		}
	}
	return 0;
}
