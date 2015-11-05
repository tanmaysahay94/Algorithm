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

bool isEven(char ch)
{
	return (ch - '0') % 2 == 0;
}

int main()
{
	string str, ans;
	cin >> str;
	int len = str.length();
	bool possible = false;
	bool evenYet = false;
	for (int i = 0; str[i] and not possible; i++)
		if (isEven(str[i]))
			possible = true;
	if (not possible)
		cout << -1 << endl;
	else
	{
		ans = str;
		int previousSwap;
		for (int i = len - 2; i >= 0; i--)
		{
			if (isEven(str[i]))
			{
				if (not evenYet)
				{
					evenYet = true;
					swap(ans[i], ans[len - 1]);
					previousSwap = i;
				}
				else
				{
					swap(str[i], str[len - 1]);
					if (str[i] > ans[i])
					{
						swap(ans[previousSwap], ans[len - 1]);
						swap(ans[i], ans[len - 1]);
						previousSwap = i;
					}
					else if (str[i] == ans[i])
						if (str[len - 1] > ans[len - 1])
						{
							swap(ans[previousSwap], ans[len - 1]);
							swap(ans[i], ans[len - 1]);
							previousSwap = i;
						}
					swap(str[i], str[len - 1]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
