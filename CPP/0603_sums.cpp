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

const LL mod = 1e9 + 7;

int main()
{
	LL a, b;
	cin >> a >> b;
	a %= mod, b %= mod;
	LL B = b * (b - 1) / 2;
	B %= mod;
	LL A = a * (a + 1) / 2;
	A %= mod;
	A = (A * b) % mod;
	A = (A + a) % mod;
	cout << (A * B) % mod << endl;
	return 0;
}
