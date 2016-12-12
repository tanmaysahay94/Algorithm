
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

LL powMod(LL a, LL b, LL m = 10)
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

int main()
{
    LL n;
    LL b = 1378;
    cin >> n;
    cout << powMod(b, n) << endl;
    /*
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
    }
    */
    return 0;
}
