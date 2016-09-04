
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

LL fpm(LL a, LL b, LL m)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ret;
}

LL solve1(LL A, LL B, LL N, LL K)
{
    LL ans = 0;
    for (LL i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j) continue;
            LL sum = fpm(i, A, K) + fpm(j, B, K);
            sum %= K;
            if (not sum) ans++;
        }
    return ans;
}

LL solve2(LL A, LL B, LL N, LL K)
{
    return 0;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        LL A, B, N, K;
        scanf("%lld%lld%lld%lld", &A, &B, &N, &K);
        printf("Case #%d: %lld\n", T, solve1(A, B, N, K));
    }
    return 0;
}
