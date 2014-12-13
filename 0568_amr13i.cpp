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
	int t;
	cin >> t;
	while (t--)
	{
		LL n;
		cin >> n;
		if (n < 4)
			cout << n << endl;
		else if (n % 2 == 0)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
	return 0;
}
