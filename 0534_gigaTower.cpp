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

bool check(LL v)
{
	while (v != 0)
	{
		LL dig = v % 10;
		if (dig == 8)
			return true;
		v /= 10;
	}
	return false;
}

int main()
{
	LL val, i = 1;
	cin >> val;
	while (true)
	{
		if (check(abs(val + i)))
			break;
		i++;
	}
	cout << i << endl;
	return 0;
}
