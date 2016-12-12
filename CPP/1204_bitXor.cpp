
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

inline LL mul(LL a, LL b, LL m) {return ((a % m) * (b % m)) % m;}

LL fPow(LL a, LL b, LL m)
{
    LL ret = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ret;
}

inline bool o(LL a) {return a & 1;}
inline bool e(LL a) {return !o(a);}

LL f(LL a, LL b, LL d, LL m)
{
    if (a == b--)
        return 0;
    LL ret = 0;
    LL terms = (b - a) / d;
    LL last = terms * d + a;
    ret = (a % m + last % m) % m;
    ret = mul(ret, fPow(2, m - 2, m), m);
    ret = mul(ret, ++terms, m);
    if (e(a) and e(d)) ret += terms;
    else if (e(a) and o(d)) ret += (terms & 1);
    else if (o(a) and e(d)) ret -= terms;
    else if (o(a) and o(d)) ret -= (terms & 1);
    ret %= m;
    if (ret < 0) ret += m;
    return ret;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        LL a, b, d, m;
        scanf("%lld%lld%lld%lld", &a, &b, &d, &m);
        printf("%lld\n", f(a, b, d, m));
    }
    return 0;
}
