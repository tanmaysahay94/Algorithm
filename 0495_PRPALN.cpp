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
	SLL(t);
	while (t--)
	{
		cin >> s;
		LL start = 0, end = s.length() - 1, error = 0;
		while (start <= end and error < 2)
		{
			if (s[start] == s[end])
			{
				start++;
				end--;
			}
			else
			{
				end--;
				error++;
			}
		}
		LL ans = error;
		start = 0, end = s.length() - 1, error = 0;
		while (start <= end and error < 2)
		{
			if (s[start] == s[end])
			{
				start++;
				end--;
			}
			else
			{
				start++;
				error++;
			}
		}
		ans = min(ans, error);
		if (ans < 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
