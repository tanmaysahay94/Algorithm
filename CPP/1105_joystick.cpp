#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

const int maxn = 1005;

int dp[maxn][maxn];

int solve(int a, int b)
{
	if (a >= maxn or b >= maxn) return 0;
	if (a <= 0 or b <= 0) return 0;
	if (a == 1 and b == 1) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = dp[b][a] = 1 + max(solve(a + 1, b - 2), solve(a - 2, b + 1));
}

int main()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			dp[i][j] = -1;
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", solve(a, b));
	return 0;
}
