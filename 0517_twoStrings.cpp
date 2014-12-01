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
	LL t;
	SLL(t);
	while (t--)
	{
		LL ans = 0;
		string a, b;
		cin >> a >> b;
		VLL c1(26, 0), c2(26, 0);
		for (LL i = 0; a[i]; i++)
			c1[a[i] - 'a']++;
		for (LL i = 0; b[i]; i++)
			c2[b[i] - 'a']++;
		for (LL i = 0; i < 26; i++)
			if (c1[i] and c2[i])
			{
				ans = 1;
				break;
			}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
