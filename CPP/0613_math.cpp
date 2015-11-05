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

VI sieve((int) 1e6 + 10, 1);

void init(int n)
{
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i <= n; i++)
		if (sieve[i])
			for (int j = 2*i; j <= n; j += i)
				sieve[j] = 0;
}

int main()
{
	int n, i;
	cin >> n;
	init(n);
	for (i = 4; i < n; i++)
		if (sieve[i] == 0 and sieve[n-i] == 0)
			break;
	cout << i << " " << n-i << endl;
	return 0;
}
