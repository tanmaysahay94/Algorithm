#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL gcd(LL a, LL b)
{
	LL r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	LL a, b, lcm, dasha, masha;
	cin >> a >> b;
	lcm = (a * b)/gcd(a, b);
	dasha = (lcm - 1)/a;
	masha = (lcm - 1)/b;
	if (abs(dasha - masha) == 1)
		cout << "Equal\n";
	else if (dasha > masha)
		cout << "Dasha\n";
	else
		cout << "Masha\n";
	return 0;
}
