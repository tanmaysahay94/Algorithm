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
	char v[105][105];
	for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++) v[i][j] = '*';
	for (int i = 0; i <= n/2; i++)
		for (int j = n/2; j >= n/2 - i; j--)
			v[i][j] = 'D';
	for (int i = 0; i <= n/2; i++)
		for (int j = n/2; j <= n/2 + i; j++)
			v[i][j] = 'D';
	for (int i = 0; i <= n/2; i++, cout << endl)
		for (int j = 0; j < n; j++)
			cout << v[i][j];
	for (int i = n/2 - 1; i >= 0; i--, cout << endl)
		for (int j = 0; j < n; j++)
			cout << v[i][j];
	return 0;
}
