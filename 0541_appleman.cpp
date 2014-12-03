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
	LL n;
	cin >> n;
	VLL v(n);
	LL ans = 0;
	for (LL i = 0;i < n; i++)
	{
		SLL(v[i]);
		ans += v[i];
	}
	sortv(v);
	for (LL i = 0; i < n; i++)
		ans += (i+1)*(v[i]);
	cout << ans-v[n-1] << endl;
	return 0;
}
