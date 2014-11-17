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
	LL n, oddEnd, evenEnd;
	cin >> n;
	if (n & 1)
		oddEnd = n/2 + 1, evenEnd = (n - 1)/2;
	else
		evenEnd = n/2, oddEnd = (n - 1)/2 + 1;
	LL ans = evenEnd * (evenEnd + 1);
	ans -= oddEnd * oddEnd;
	cout << ans << endl;
	return 0;
}
