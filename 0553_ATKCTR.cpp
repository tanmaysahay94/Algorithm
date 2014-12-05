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

VI out(1000010);

int main()
{
	int t;
	SI(t);
	while (t--)
	{
		int n, k, x, y, flag = 0;
		SI(n);
		out = VI (out.size(), 0);
		for (int i = 1; i <= n; i++)
			out[i] = i - 1;
		SI(k);
		for (int i = 0; i < k; i++)
		{
			SI(x); SI(y);
			out[x]++;
			out[y]--;
		}
		for (int i = 1; i <= n; i++)
		{
			if (out[i] == n - 1)
			{
				printf("2 %d\n", i);
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("1\n");
	}
	return 0;
}
