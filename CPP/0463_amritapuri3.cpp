#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int s, q;
	char a[20200];
	int m, l;
	scanf("%s", a);
	s = strlen(a);
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &m, &l);
		LL sum = 0;
		vector< vector<int> >dp(s, vector<int>(m, 0));
		dp[0][(a[0]-'0')%m] = 1;
		sum += dp[0][l];
		for(int i = 1; i < s; i++)
		{
			dp[i][(a[i]-'0')%m] = 1;
			for(int j = 0; j < m; j++)
				dp[i][10*j + a[i]-'0'] += dp[i-1][j];
			sum += dp[i][l];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
