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
	int n;
	si(n);
	VI v(n);
	for (int i = 0; i < n; i++)
		si(v[i]);
	int cnt = v[n - 1] > v[0], idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[i - 1])
		{
			cnt++;
			idx = n - i;
		}
	}
	if (cnt > 1)
		cout << -1 << endl;
	else
		cout << idx << endl;
	return 0;
}
