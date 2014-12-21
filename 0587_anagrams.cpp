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
	string str;
	cin >> str;
	VI count(26, 0);
	VLL fact(13);
	fact[0] = 1;
	for (int i = 1; i < 13; i++)
		fact[i] = fact[i - 1] * i;
	for (int i = 0; i < (int)str.length(); i++)
		count[str[i] - 'a']++;
	LL ans = fact[str.length()];
	for (int i = 0; i < 26; i++)
		if (count[i])
			ans /= fact[count[i]];
	printf("%lld\n", ans);
	return 0;
}
