#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	VLL v(3);
	cin >> v[0] >> v[1] >> v[2];
	sortv(v);
	if (v[2] >= 2*(v[0] + v[1]))
		cout << v[0] + v[1] << endl;
	else
		cout << (v[0] + v[1] + v[2])/3 << endl;
	return 0;
}
