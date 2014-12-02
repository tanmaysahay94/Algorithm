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

LL gcd(LL a, LL b)
{
	if (not b) return a;
	return gcd(b, a % b);
}

int main()
{
	VLL person(3333333);
	string s[] = {"Vanya", "Vova"};
	LL n, x, y;
	SLL(n); SLL(x); SLL(y);
	LL g = gcd(x, y);
	x /= g;
	y /= g;
	LL hits = x + y;
	swap(x, y);
	LL xx = x;
	LL yy = y;
	for (LL i = 1; i <= hits; i++)
	{
		if (xx < yy)
		{
			person[i] = 0;
			xx += x;
		}
		else
		{
			person[i] = 1;
			yy += y;
		}
	}
	LL a;
	for (LL i = 1; i <= n; i++)
	{
		SLL(a);
		a %= hits;
		if (a == 0 or a == hits - 1)
			cout << "Both" << endl;
		else
			cout << s[person[a]] << endl;
	}
	return 0;
}
