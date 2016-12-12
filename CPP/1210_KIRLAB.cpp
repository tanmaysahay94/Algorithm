
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

const LL maxn = 1e5 + 5;

LL a[maxn], dp[maxn];

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", &a[i]);
            dp[i] = 1;
        }
        LL ans = 1;
        for (int i = 1; i < N; i++)
            for (int j = 0; j < i; j++)
                if (__gcd(a[i], a[j]) > 1)
                    dp[i] = max(dp[i], dp[j] + 1);
        for (int i = 0; i < N; i++)
            ans = max(ans, dp[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
