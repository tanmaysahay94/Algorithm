

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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> is(n), dist(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int loc;
        scanf("%d", &loc);
        is[loc] = 1;
    }
    int v = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (is[i])
            v = 0;
        else
            v++;
        dist[i] = min(dist[i], v);
    }
    v = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (is[i])
            v = 0;
        else
            v++;
        dist[i] = min(dist[i], v);
    }
    int ans = INT_MIN;
    for (auto &d: dist)
        ans = max(ans, d);
    cout << ans;
    return 0;
}
