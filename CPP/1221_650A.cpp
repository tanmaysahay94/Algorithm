
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
#include <unordered_set>
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

inline LL f(int x)
{
    LL ret(x);
    return (ret * (ret - 1)) / 2;
}

inline LL h(int a, int b, int sz)
{
    LL ret(sz);
    ret *= a;
    ret += b;
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> P(n);
    set<int> S;
    unordered_map<int, int> fwd;
    unordered_map<LL, int> uniq;
    for (auto &p: P) 
    {
        scanf("%d%d", &p.first, &p.second);
        S.insert(p.first); S.insert(p.second);
    }
    int cnt = 0;
    for (auto it = S.begin(); it != S.end(); it++, cnt++)
        fwd[*it] = cnt;
    vector<int> x_axis(S.size()), y_axis(S.size());
    for (auto &p: P)
    {
        x_axis[fwd[p.first]]++, y_axis[fwd[p.second]]++;
        uniq[h(fwd[p.first], fwd[p.second], cnt)]++;
    }
    LL ans = 0;
    for (auto &x: x_axis)
        ans += f(x);
    for (auto &y: y_axis)
        ans += f(y);
    for (auto &u: uniq)
        ans -= f(u.second);
    printf("%lld\n", ans);
    return 0;
}
