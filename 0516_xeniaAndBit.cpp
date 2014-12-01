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

int main()
{
	int n, m;
	SI(n); SI(m);
	int lim = 1<<(n+1);
	VI st(lim, 0);
	int i, j, step;
	for (i = 0; i < lim/2; i++)
		SI(st[lim/2 + i]);
	for (i = n-1, step = 0; i >= 0; i--, step ^= 1)
		for (j = 1<<i; j < 1<<(i+1); j++)
			if (step)
				st[j] = st[2*j] ^ st[2*j+1];
			else
				st[j] = st[2*j] | st[2*j+1];
	while (m--)
	{
		int p, b;
		SI(p); SI(b);
		int idx = lim/2 + p - 1;
		st[idx] = b; 
		idx >>= 1;
		step = 1;
		while (idx)
		{
			if (step)
				st[idx] = st[2*idx] | st[2*idx+1];
			else
				st[idx] = st[2*idx] ^ st[2*idx+1];
			step ^= 1;
			idx >>= 1;
		}
		printf("%d\n", st[1]);
	}
	return 0;
}
