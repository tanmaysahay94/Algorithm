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

long long int phi(long long x) // euler totient function (etf)
{
	long long int ret = 1, i, pow;
	for (i = 2; x != 1; i++) 
	{
		pow = 1;
		if(i > sqrt(x))
			break;
		while (!(x%i)) 
		{
			x /= i;
			pow *= i;
		}
		ret *= (pow - (pow/i));
	}
	if(x!=1)
		ret *= x-1;
	return ret;
}

int main()
{
	LL n;
	cin >> n;
	cout << phi(n) << endl;
}
