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
	LL t, i, ans;
	string b, w;
	vector<LL> first(26), second(26);
	SLL(t);
	while (t--)
	{
		for (i = 0; i < 26; i++)
			first[i] = second[i] = 0;
		ans = 0;
		cin >> b >> w;
		for (i = 0; b[i]; i++)
			first[b[i] - 'a']++;
		for (i = 0; w[i]; i++)
			second[w[i] - 'a']++;
		for (i = 0; i < 26; i++)
			if (first[i] and second[i])
				ans++;
		printf("%lld\n", ans);
	}
	return 0;
}
