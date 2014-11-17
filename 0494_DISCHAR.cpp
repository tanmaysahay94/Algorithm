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
	string s;
	VLL v(26);
	SLL(t);
	while (t--)
	{
		LL ans = 0;
		cin >> s;
		for (LL i = 0; i < 26; i++)
			v[i] = 0;
		for (LL i = 0; s[i]; i++)
			v[s[i] - 'a'] = 1;
		for (LL i = 0; i < 26; i++)
			ans += v[i];
		printf("%lld\n", ans);
	}
	return 0;
}
