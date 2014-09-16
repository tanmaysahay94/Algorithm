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
	LL n, nr = 1, dr = 720, hcf, mod = 1e9 + 7;
	vector<LL> list;
	cin >> n;
	if (n < 13)
	{
		cout << 0 << endl;
		return 0;
	}
	n -= (!(n & 1));
	n = (n - 13)/2;
	for (int i = n + 6; i >= n - 1; i--)
		list.pb(i);
	for (int i = 0; i < 6; i++)
	{
		hcf = gcd(list[i], dr);
		list[i] /= hcf;
		dr /= hcf;
		nr = (nr * list[i]) % mod;
	}
	cout << nr << endl;
	return 0;
}
