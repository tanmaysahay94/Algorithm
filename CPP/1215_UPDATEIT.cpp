
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
const int maxn = 10005;

LL T[maxn];
int N;

LL query(int idx)
{
    LL sum = 0;
    for (; idx; idx -= (idx & (-idx)))
        sum += T[idx];
    return sum;
}

void update(int idx, int val)
{
    for (; idx <= N; idx += (idx & (-idx)))
        T[idx] += val;
}

void r_update(int l, int r, int val)
{
    update(l, val);
    update(r + 1, -val);
}

void init()
{
    for (int i = 0; i <= N; i++) T[i] = 0;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int u;
        scanf("%d%d", &N, &u);
        init();
        while (u--)
        {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            r_update(++l, ++r, val);
        }
        scanf("%d", &u);
        while (u--)
        {
            int idx;
            scanf("%d", &idx);
            printf("%lld\n", query(++idx));
        }
    }
    return 0;
}
