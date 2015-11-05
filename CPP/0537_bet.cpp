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
	LL a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if ((a+b+c+d+e)%5==0 and (a+b+c+d+e))
		printf("%lld\n", (a+b+c+d+e)/5);
	else
		printf("-1\n");
	return 0;
}
