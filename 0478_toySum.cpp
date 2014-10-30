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
	LL inf = 1e6;
	LL n;
	SLL(n);
	vector<pair<LL, int> > arr(n);
	VLL ans;
	VI present(inf + 5, 0);
	for (int i = 0; i < n; i++)
	{
		SLL(arr[i].f);
		arr[i].s = 0;
		present[arr[i].f] = 1;
	}
	sortv(arr);
	for (int i = 0; i < n; i++)
	{
		LL cur = arr[i].f;
		LL sym = inf + 1 - cur;
		if (not arr[i].s)
		{
			if (not present[sym])
			{
				present[sym] = 1;
				ans.pb(sym);
			}
			else
			{
				LL done = 0, shift = 0, high = max(cur, sym), low = min(cur, sym);
				while (low - shift >= 1 and high + shift <= inf)
				{
					if (not present[low - shift] and not present[high + shift])
					{
						ans.pb(low - shift);
						ans.pb(high + shift);
						done = 1;
						present[low - shift] = present[high + shift] = 1;
						break;
					}
					shift++;
				}
				if (not done)
				{
					shift = 0;
					while (high - shift >= low + shift)
					{
						if (not present[high - shift] and not present[low + shift])
						{
							ans.pb(high - shift);
							ans.pb(low + shift);
							done = 1;
							present[low + shift] = present[high - shift] = 1;
							break;
						}
						shift++;
					}
				}
				vector<pair<LL, int> >::iterator p;
				p = lower_bound(arr.begin(), arr.end(), mp(sym, 0));
				p -> s = 1;
			}
			arr[i].s = 1;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
