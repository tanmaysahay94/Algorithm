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
	LL n;
	cin >> n;
	vector<VLL> v(n, VLL(n));
	for (LL i = 0; i < n; i++)
		v[i][0] = v[0][i] = 1;
	for (LL i = 1; i < n; i++)
		for (LL j = 1; j < n; j++)
			v[i][j] = v[i-1][j] + v[i][j-1];
	cout << v[n-1][n-1] << endl;
	return 0;
}
