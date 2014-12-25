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
	cin >> n;
	VI v(n), u(n);
	string str;
	cin >> str;
	for (int i = 0; i < n; i++)
		v[i] = str[i] - '0';
	int carry = 1, ans = 0;
	for (int i = 0; i < n; i++)
	{
		u[i] = v[i] ^ carry;
		carry &= v[i];
		if (u[i] != v[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
