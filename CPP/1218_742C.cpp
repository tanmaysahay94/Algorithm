
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

inline int lcm(int a, int b) {return (int) (((long long) a * (long long) b) / __gcd(a, b));}

int f(int start, int curr, vector<int>& crush, vector<int>& vis, int len = 0)
{
    if (vis[curr])
        return curr == start ? (len == 2 ? 1 : len) : -1;
    vis[curr] = 1;
    return f(start, crush[curr], crush, vis, len + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> crush(n), vis(n, 0);
    for (auto &c: crush)
    {
        scanf("%d", &c);
        c--;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int stat = f(i, i, crush, vis);
        if (stat == -1)
        {
            ans = -1;
            break;
        }
        else
        {
            if (stat % 2 == 0)
                stat >>= 1;
            ans = lcm(ans, stat);
        }
        vis = vector<int> (n);
    }
    printf("%d\n", ans);
    return 0;
}
