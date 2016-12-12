
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

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N;
        scanf("%d", &N);
        N--;
        int q = N / 8;
        int r = N % 8;
        if (r < 3) r += 3;
        else if (r < 6) r -= 3;
        else r ^= 1;
        string loc;
        if (r == 6) loc = "SL";
        else if (r == 7) loc = "SU";
        else if (r % 3 == 0) loc = "LB";
        else if (r % 3 == 1) loc = "MB";
        else loc = "UB";
        printf("%d%s\n", 8 * q + r + 1, loc.c_str());
    }
    return 0;
}
