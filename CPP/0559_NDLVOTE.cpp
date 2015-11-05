#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n;
	si(n);
	while (n)
	{
		char ch;
		int ans = 0, val;
		for (int i = 0; i < n; i++)
		{
			getchar();
			scanf("%c%d", &ch, &val);
			if (ch == 'P')
				val--;
			else
				val++;
			if (abs(val) >= ans)
				ans = abs(val);
			else if ((ans - abs(val)) & 1)
				ans++;
		}
		printf("%d\n", ans);
		si(n);
	}
	return 0;
}
