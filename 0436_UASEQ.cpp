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
	LL n, k, i, j, p, minStart = 1e10, minDiff = 1e10;
	cin >> n >> k;
	VLL arr(n), out;
	for (i = 0; i < n; i++)
		SLL(arr[i]);
	for (i = 0; i < k + 2; i++)
	{
		for (j = i + 1; j < k + 2; j++)
		{
			LL count = 0;
			LL diff = arr[j] - arr[i];
			LL start = arr[i] - i * diff;
			for (p = 0; p < n; p++)
				if (arr[p] != start + p * diff)
					count++;
			if (count <= k)
			{
				if (start < minStart)
				{
					minStart = start;
					minDiff = diff;
				}
				else if (start == minStart)
					minDiff = min(minDiff, diff);
			}
		}
	}
	for (i = 0; i < n; i++)
		out.push_back(minStart + i * minDiff);
	for (i = 0; i < n - 1; i++)
		cout << out[i] << " ";
	cout << out[i] << endl;
	return 0;
}
