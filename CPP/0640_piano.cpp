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

int main()
{
	int n, k, i;
	si(n); si(k);
	VLL v(n);
	LL sum = 0, mn = INT_MAX, idx = 1;
	for (i = 0; i < n; i++)
		sll(v[i]);
	for (i = 0; i < k; i++)
		sum += v[i];
	mn = sum;
	LL start = 0;
	for (; i < n; i++, start++)
	{
		sum += v[i] - v[start];
		if (sum < mn)
		{
			mn = sum;
			idx = start + 2;
		}
	}
	printf("%lld\n", idx);
	return 0;
}
