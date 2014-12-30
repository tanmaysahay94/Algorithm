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

int is[2001][2001];

int is_fn(string& str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
		is[i][i] = 1;
	for (int i = 1; i < len; i++)
		for (int j = 0; j < i; j++)
			if (str[i] == str[j])
				if (i - j > 1)
					if (is[j + 1][i - 1])
						is[j][i] = 1;
					else
						is[j][i] = 0;
				else
					is[j][i] = 1;
			else
				is[j][i] = 0;
	return len;
}

int main()
{
	string str;
	cin >> str;
	int len = is_fn(str);
	VLL palin(len);
	palin[0] = 1;
	for (int i = 1; i < len; i++)
	{
		palin[i] = palin[i - 1];
		for (int j = 0; j <= i; j++)
			palin[i] += is[j][i];
	}
	VLL dp(len);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < len; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 1; j <= i; j++)
			if (is[j][i])
				dp[i] += palin[j - 1];
	}
	cout << dp[len - 1] << endl;
	return 0;
}
