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
	int n, k;
	cin >> n >> k;
	k--;
	int cur(1), last(n);
	while (k > 1)
	{
		cout << cur << " " << n - cur + 1 << " ";
		k -= 2; last = n - cur; cur++;
	}
	if (k)
	{
		for (int i = cur; i < last - 1; i++)
			cout << i << " ";
		cout << last << " " << last - 1 << endl;
	}
	else
	{
		for (int i = cur; i <= last; i++)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
