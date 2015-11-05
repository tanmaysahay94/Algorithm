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
	VLL v;
	v.pb(2);
	v.pb(7);
	v.pb(2);
	v.pb(3);
	v.pb(3);
	v.pb(4);
	v.pb(2);
	v.pb(5);
	v.pb(1);
	v.pb(2);
	string str;
	cin >> str;
	int ans = 1;
	for (int i = 0; i < 2; i++)
		ans *= v[str[i] - '0'];
	cout << ans << endl;
	return 0;
}
