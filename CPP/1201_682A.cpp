
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

unordered_map<int, long long> f(int n)
{
    unordered_map<int, long long> ret;
    int c = n / 5;
    for (int i = 0; i < 5; i++) ret[i] = c;
    int m = n % 5;
    for (int i = 1; i <= m; i++) ret[i]++;
    for (auto &r: ret) trace(r.first, r.second);
    return ret;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    auto c1 = f(n);
    auto c2 = f(m);
    long long ans = 0;
    for (auto &c: c1) ans += c.second * c2[(5 - c.first) % 5];
    printf("%lld\n", ans);
    return 0;
}
