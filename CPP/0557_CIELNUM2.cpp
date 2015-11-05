#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n, count = 0;
	char str[111];
	si(n);
	gets(str);
	while (n--)
	{
		gets(str);
		int len = strlen(str);
		int only = 1;
		int c3 = 0, c5 = 0, c8 = 0;
		for (int i = len - 1; only and i > 0 and str[i] != ' '; i--)
		{
			if (str[i] == '3')
				c3++;
			else if (str[i] == '5')
				c5++;
			else if (str[i] == '8')
				c8++;
			else if (str[i] >= '0' and str[i] <= '9')
				only = 0;
		}
		if (only and c8 >= c5 and c5 >= c3)
			count++;
	}
	cout << count << endl;
	return 0;
}
