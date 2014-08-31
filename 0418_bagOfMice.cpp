#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	double dp[1010][1010];
	int w, b, i, j;
	cin >> w >> b;
	for (i = 0; i <= b; i++)
		dp[0][i] = 0;
	for (i = 1; i <= w; i++)
		dp[i][0] = 1;
	for (i = 1; i <= w; i++)
		for (j = 1; j <= b; j++)
		{
			dp[i][j] += i * 1.0 / (i + j);
			if (j >= 2) 
				dp[i][j] += (j * 1.0 / (i + j) * (j - 1) / (i + j - 1) * i * 1.0 / (i + j - 2)) * dp[i - 1][j - 2];
			if (j >= 3) 
				dp[i][j] += (j * 1.0 / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2)) * dp[i][j - 3];
		}
	printf("%.9f\n", dp[w][b]);
	return 0;
}
