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

int main()
{
	LL n, k, i;
	SLL(n); SLL(k);
	VLL array(n);
	map<LL, LL> diff;
	for (i = 0; i < n; i++)
		SLL(array[i]);
/*	for (i = 0; i < n - 1; i++)
	{
		LL d = array[i + 1] - array[i];
		if (diff.find(d) == diff.end())
			diff[d] = 1;
		else
			diff[d]++;
	}
	for (map<LL, LL>::iterator it = diff.begin(); it != diff.end(); ++it)
	{
	}*/
	return 0;
}
