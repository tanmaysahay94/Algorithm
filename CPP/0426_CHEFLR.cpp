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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t, i, ans, mod = 1e9 + 7;
	string s;
	SLL(t);
	while (t--)
	{
		ans = 1;
		cin >> s;
		for (i = 0; s[i]; i++)
			if (i & 1)
				if (s[i] == 'l')
					ans = (ans * 2 - 1) % mod;
				else
					ans = (ans * 2 + 1) % mod;
			else
				if (s[i] == 'l')
					ans = (ans * 2) % mod;
				else
					ans = (ans * 2 + 2) % mod;
		cout << ans << endl;
	}
	return 0;
}
