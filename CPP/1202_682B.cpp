
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
    int n;
    scanf("%d", &n);
    multiset<int> S;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        S.insert(val);
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++)
    {
        auto it = S.lower_bound(i);
        if (it == S.end())
        {
            ans = i;
            break;
        }
        S.erase(it);
    }
    printf("%d\n", ans);
    return 0;
}
