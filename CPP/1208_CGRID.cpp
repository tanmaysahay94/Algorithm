
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>
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
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        vector<vector<LL> > C(N, vector<LL> (M));
        auto P(C);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%lld", &C[i][j]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%lld", &P[i][j]);
        LL dp[N][M][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = C[0][0];
        dp[0][0][1] = C[0][0];
        for (int row = 1; row < N; row++)
        {
            dp[row][0][0] = dp[row - 1][0][0] + C[row][0];
            dp[row][0][1] = dp[row][0][0] + P[row][0];
        }
        for (int col = 1; col < M; col++)
        {
            dp[0][col][1] = dp[0][col - 1][1] + C[0][col];
            dp[0][col][0] = dp[0][col][1] + P[0][col];
        }
        for (int row = 1; row < N; row++)
            for (int col = 1; col < M; col++)
            {
                LL fromUp = dp[row - 1][col][0];
                LL fromLe = dp[row][col - 1][1];
                if (row == N - 1 and col == M - 1)
                {
                    dp[row][col][0] = C[row][col] + fromUp;
                    dp[row][col][1] = C[row][col] + fromLe;
                    break;
                }
                dp[row][col][0] = C[row][col] + min(fromUp, fromLe + P[row][col]);
                dp[row][col][1] = C[row][col] + min(fromLe, fromUp + P[row][col]);
            }
        printf("%lld\n", min(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]));
    }
    return 0;
}
