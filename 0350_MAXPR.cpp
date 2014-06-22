#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<ULL, ULL> PULL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PULL> VPULL;

#define FORL(i, a, b) for (i = a; i <= b; i++)

int main()
{
	ULL t, n, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		VLL v(n), dp(n, 0);
		FORL(i, 0, n - 1) cin >> v[i];
		FORL(i, -100, 100)
		{
			FORL(j, 0, n - 1)
			{
			}
		}
	}
}
