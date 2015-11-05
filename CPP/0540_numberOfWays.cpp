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
	VLL v(n), p(n);
	for (LL i = 0; i <n; i++)
		SLL(v[i]);
	p[0] = v[0];
	for (LL i = 1; i < n; i++)
		p[i] = p[i-1] + v[i];
	if (p[n-1] % 3)
		cout << "0\n";
	else
	{
		LL sum = p[n-1];
		LL a = sum/3;
		LL b = a<<1;
		LL ans = 0;
		VLL pre(555555);
		pre[0] = 0;
		for (LL i = 1; i <= n; i++)
			pre[i] = pre[i-1] + (p[i-1]==a);
		for (LL i = 1; i < n - 1; i++)
			if (p[i] == b)
				ans += pre[i];
		cout << ans << endl;
	}
	return 0;
}
