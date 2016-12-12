
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

int f(int i, int j, int n)
{
    i += j;
    i %= n;
    return i ? i : n;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n, m, d, D;
        scanf("%d%d%d%d", &n, &m, &d, &D);
        if (m < n * d or m > n * D)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < d; j++)
                printf("%d %d\n", i, f(i, j, n));
        int remaining = m - n * d;
        while (remaining)
        {
            for (int i = 1; i <= n and remaining; i++)
                for (int j = d; remaining and j < D; j++, remaining--)
                    printf("%d %d\n", i, f(i, j, n));
        }
    }
    return 0;
}
