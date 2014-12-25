#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

VLL height;
LL n, m, w;

bool check(LL val)
{
	VLL sum(n+1, 0);
	for (LL i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1];
		LL cur = height[i] + sum[i - 1] - sum[max(i - w, 0LL)];
		if (cur < val)
			sum[i] += val - cur;
	}
	return sum[n] <= m;
}

int main()
{
	cin >> n >> m >> w;
	height.resize(n+1);
	for (LL i = 1; i <= n; i++)
		cin >> height[i];
	LL low = 0, high = (LL)1e9 + (LL) 1e5;
	while (low <= high)
	{
		LL mid = (low + high) >> 1;
		if (check(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high << endl;
	return 0;
}
