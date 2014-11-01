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

vector<VLL> ans(10, VLL ((int) (1e5) + 10, 0));
int main()
{
	LL n, m, idx;
	SLL(n); SLL(m);
	string s;
	cin >> s;
	for (LL i = 0LL; i < 10; i++)
	{
		ans[i][0] = abs(i - (s[0] - '0'));
		for (LL j = 1LL; s[j]; j++)
			ans[i][j] = ans[i][j - 1] + abs(i - (s[j] - '0'));
	}
	while (m--)
	{
		SLL(idx);
		idx--;
		printf("%lld\n", ans[s[idx] - '0'][idx]);
	}
	return 0;
}
