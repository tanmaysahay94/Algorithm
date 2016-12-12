
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

inline LL f(char& c){return c - '0';}

LL solve(string& A, string& B)
{
    LL la = A.size();
    LL lb = B.size();
    vector<vector<LL> > dp(la + 1, vector<LL> (lb + 1));
    dp[0][0] = 0;
    for (int col = 1; col <= lb; col++)
        dp[0][col] = dp[0][col - 1] + f(B[col - 1]);
    for (int row = 1; row <= la; row++)
        dp[row][0] = dp[row - 1][0] + f(A[row - 1]);
    for (int row = 1; row <= la; row++)
        for (int col = 1; col <= lb; col++)
        {
            if (A[row - 1] == B[col - 1])
                dp[row][col] = dp[row - 1][col - 1];
            else
                dp[row][col] = min(dp[row][col - 1] + f(B[col - 1]),
                                dp[row - 1][col] + f(A[row - 1]));
        }
    return dp[la][lb];
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        string A, B;
        cin >> A >> B;
        printf("%lld\n", solve(A, B));
    }
    return 0;
}
