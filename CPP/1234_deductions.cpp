
#include "bits/stdc++.h"
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

typedef long long LL;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<LL>> mat(n, vector<LL>(m));
    vector<vector<LL>> dp(n, vector<LL>(m, LLONG_MAX));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &mat[i][j]);
    for (int i = 0; i < m; i++)
        dp[0][i] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                dp[i][j] = min(dp[i][j], abs(mat[i][j] - mat[i - 1][k]) + dp[i - 1][k]);
    LL ans = LLONG_MAX;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[n - 1][i]);
    printf("%lld\n", ans);
    return 0;
}
