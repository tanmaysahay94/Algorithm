
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
        printf("Case #%d: ", T);
        int n;
        scanf("%d", &n);
        multiset<int> M;
        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            M.insert(val);
        }
        int ans = 0;
        while (M.size())
        {
            int curr = 0;
            auto high = M.end();
            high--;
            curr += *high;
            M.erase(high);
            if (curr >= 50)
            {
                ans++;
                continue;
            }
            int req = (49 / curr);
            if (M.size() < req)
                break;
            for (int i = 0; i < req; i++)
            {
                auto it = M.begin();
                M.erase(it);
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
