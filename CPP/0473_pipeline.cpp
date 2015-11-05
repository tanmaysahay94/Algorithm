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
#define val(p) ((p)*(p+1)/2)

LL getval(LL start, LL end, LL n)
{
//	printf("%lld %lld %lld\n", start, end, n);
	if(start == end)
		return start;
	LL mid = (start+end)/2;
	if(val(mid) == n)
		return mid;
	if(val(mid)<n)
		if(start == mid)
			if(val(end) <= n)
				return end;
			else
				return mid;
		else
			return getval(mid, end, n);
	else
		return getval(start, mid, n);
}

int main()
{
	LL n, k;
	SLL(n); SLL(k);
	k--; n--;
	LL maxval = val(k);
	if (n > maxval)
		printf("-1\n");
	else
	{
		LL tmp = maxval - n;
		LL p = getval(0, k, tmp);
		printf("%lld\n", k-p);
	}
	return 0;
}
