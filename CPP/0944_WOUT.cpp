#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long n, h;
vector<long long> V(maxn), fenwick(maxn);
long long Q(int idx)
{
	long long ret = 0;
	while (idx > 0)
	{
		ret += fenwick[idx];
		idx -= (idx & (-idx));
	}
	return ret;
}
void U(int idx, long long val)
{
	while (idx <= n)
	{
		fenwick[idx] += val;
		idx += (idx & (-idx));
	}
}
void rU(int low, int high) 
{
	U(low, (long long)1), U(high + 1, (long long)-1);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &h);
		long long total = 0;
		for (int i = 0; i <= n; i++)
			fenwick[i] = 0;
		long long low, high;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &low, &high);
			rU(low + 1, high + 1);
		}
		for (int i = 0; i < n; i++)
			V[i] = n - Q(i + 1);
		for (int i = 0; i < h; i++)
			total += V[i];
		long long minval = total;
		for (int i = h; i < n; i++)
		{
			total += V[i] - V[i - h];
			minval = min(minval, total);
		}
		printf("%lld\n", minval);
	}
	return 0;
}
