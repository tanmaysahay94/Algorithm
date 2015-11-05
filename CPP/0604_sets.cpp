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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, k;
	cin >> n >> k;
	cout << k * (6 * n - 1) << endl;
	for (int i = 0; i < n; i++)
		cout << k*(6*i + 1) << " " << k*(6*i + 2) << " " << k*(6*i + 3) << " " << k*(6*i + 5) << endl;
	return 0;
}
