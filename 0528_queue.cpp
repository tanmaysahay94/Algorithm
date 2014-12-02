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
	LL n, a, b;
	SLL(n);
	VLL ans(n), fwd(1000100, -1), bwd(1000100, -1);
	while (n--)
	{
		SLL(a); SLL(b);
		fwd[a] = b;
		bwd[b] = a;
	}
	LL start;
	for (start = 0; start < 1000100; start++)
		if (fwd[start] != -1 and bwd[start] == -1)
			break;
	ans[0] = start;
	ans[1] = fwd[0];
	for (LL i = 2; i < ans.size(); i++)
		ans[i] = fwd[ans[i - 2]];
	for (LL i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
