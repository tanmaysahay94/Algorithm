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
		string s;
		cin >> s;
		LL len = s.length();
		LL bal = 0, max_bal = 0;
		for (LL i = 0; i < len; i++)
		{
			if (s[i] == '(')
				bal++;
			else
				bal--;
			max_bal = max(max_bal, bal);
		}
		for (LL i = 0; i < max_bal; i++)
			printf("(");
		for (LL i = 0; i < max_bal; i++)
			printf(")");
		printf("\n");
	}
	return 0;
}
