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

int main()
{
	int t;
	si(t);
	char str[15];
	while (t--)
	{
		vector<string> ans;
		scanf("%s", str);
		int count = 0;
		for (int i = 0; i < 12 and not count; i++)
			if (str[i] == 'X')
				count++;
		if (count)
			ans.pb(string("1x12 "));
		count = 0;
		for (int i = 0; i < 6 and not count; i++)
			if (str[i] == 'X' and str[i + 6] == 'X')
				count++;
		if (count)
			ans.pb(string("2x6 "));
		count = 0;
		for (int i = 0; i < 4 and not count; i++)
			if (str[i] == 'X' and str[i + 4] == 'X' and str[i + 8] == 'X')
				count++;
		if (count)
			ans.pb(string("3x4 "));
		count = 0;
		for (int i = 0; i < 3 and not count; i++)
			if (str[i] == 'X' and str[i + 3] == 'X' and str[i + 6] == 'X' and str[i + 9] == 'X')
				count++;
		if (count)
			ans.pb(string("4x3 "));
		count = 0;
		for (int i = 0; i < 2 and not count; i++)
			if (str[i] == 'X' and str[i + 2] == 'X' and str[i + 4] == 'X' and str[i + 6] == 'X' and str[i + 8] == 'X' and str[i + 10] == 'X')
				count++;
		if (count)
			ans.pb(string("6x2 "));
		count = 0;
		for (int i = 0; i < 12; i++)
			if (str[i] == 'X')
				count++;
		if (count == 12)
			ans.pb(string("12x1"));
		cout << ans.size() << ' ';
		for (int i = 0; i < (int) ans.size(); i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
