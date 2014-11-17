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
	LL a, m;
	SLL(a); SLL(m);
	VLL mod(m, 0);
	while (not mod[a % m])
	{
		mod[a % m] = 1;
		a = a + (a % m);
	}
	if (not mod[0]) printf("No\n");
	else printf("Yes\n");
	return 0;
}
