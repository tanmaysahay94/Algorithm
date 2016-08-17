
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

typedef long long LL;

const LL inf = LLONG_MAX;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<string> >S(2, vector<string> (n));
    vector<LL> cost(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &cost[i]);
    for (int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        S[0][i] = w;
        reverse(w.begin(), w.end());
        S[1][i] = w;
    }
    vector<vector<LL> > dp(2, vector<LL> (n));
    dp[0][0] = 0;
    dp[1][0] = cost[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            LL &val = dp[j][i];
            val = inf;
            for (int k = 0; k < 2; k++)
                if (S[j][i] >= S[k][i - 1])
                    if (dp[k][i - 1] < inf)
                        val = min(val, dp[k][i - 1] + cost[i] * j);
        }
    LL ans = inf;
    for (int i = 0; i < 2; i++)
        ans = min(ans, dp[i][n - 1]);
    printf("%lld\n", ans == inf? -1: ans);
    return 0;
}
