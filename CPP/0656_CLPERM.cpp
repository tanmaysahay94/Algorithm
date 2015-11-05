#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

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

LL sum(LL n)
{
	return (n * (n + 1))/2;
}

LL rangeSum(LL low, LL high)
{
	return sum(high) - sum(low - 1);
}

LL vectorsum(VLL& v)
{
	LL ret = 0;
	for (int i = 0; i < (int) v.size(); i++)
		ret += v[i];
	return ret;
}

int calc(VLL& missing, LL n)
{
	LL k = missing.size();
	if (missing[0] <= 2)
		return missing[0];
	if (k == 1)
		return (sum(n) - missing[0] + 1);
	LL i = 0, presum = sum(missing[i] - 1);
	while (i < k)
	{
		LL x = missing[i] - 1;
		if (i == 0)
			presum = sum(x);
		else
			presum += rangeSum(missing[i - 1] + 1, x);
		bool inc = false;
		while (i < k - 1 and missing[i] + 1 == missing[i + 1])
		{
			inc = true;
			i++;
		}
		x = missing[i] + 1;
		if (presum + 1 < x)
			return (presum + 1);
		else
		{
			if (i == k - 1)
				return sum(n) - vectorsum(missing) + 1;
			else if (not inc)
				i++;
		}
	}
}

int main()
{
	LL t;
	sll(t);
	while (t--)
	{
		LL n, k;
		sll(n); sll(k);
		if (k == 0)
		{
			if ((sum(n) + 1) % 2)
				printf("Chef\n");
			else
				printf("Mom\n");
			continue;
		}
		VLL v(k);
		for (int i = 0; i < k; i++)
			sll(v[i]);
		sortv(v);
		if (calc(v, n) % 2)
			printf("Chef\n");
		else
			printf("Mom\n");
	}
}
