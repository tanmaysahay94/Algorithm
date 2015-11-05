#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n;
	si(n);
	vector<ULL> a(n), gauss(65);
	for (int i = 0; i < n; i++)
		sull(a[i]);
	sort(a.begin(), a.end(), greater<ULL>());
	for (int i = 0; i < n; i++)
		for (int j = 62; j >= 0; j--)
			if (a[i] & (1ULL << j))
				if (!gauss[j])
				{
					gauss[j] = a[i];
					break;
				}
				else
					a[i] ^= gauss[j];
	ULL ans = 0;
	for (int i = 62; i >= 0; i--)
		if (!(ans & (1ULL << i)))
			ans ^= gauss[i];
	printf("%llu\n", ans);
}
