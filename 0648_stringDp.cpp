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

map<int, LL> mp;

int main()
{
	LL k;
	string str;
	cin >> k >> str;
	LL len = str.length();
	VI pre(len + 1, 0);
	mp[0] = 1;
	for (LL i = 1; i <= len; i++)
	{
		pre[i] = pre[i - 1] + (str[i - 1] == '1');
		mp[pre[i]]++;
	}
	LL ans = 0;
	if (k)
		each(it, mp)
			if (it->f > pre[len] - k)
				break;
			else
				ans += it->s * mp[it->f + k];
	else
	{
		LL cnt = 0;
		for (LL i = 0; i < len; i++)
		{
			if (str[i] == '0')
				cnt++;
			else
			{
				ans += (cnt * (cnt + 1))/2;
				cnt = 0;
			}
		}
		if (cnt)
			ans += (cnt * (cnt + 1))/2;
	}
	cout << ans << endl;
	return 0;
}
