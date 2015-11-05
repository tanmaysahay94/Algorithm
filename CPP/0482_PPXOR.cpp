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

vector<LL> a((int) 1e5 + 10);
int main()
{
	LL t, n;
	SLL(t);
	while (t--)
	{
		SLL(n);
		for (LL i = 0; i < n; i++)
			SLL(a[i]);
	}
	return 0;
}
