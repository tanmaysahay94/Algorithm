
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
int N;
const LL inf = LLONG_MAX;
const LL mod = 100;

pair<LL, LL> solve(vector<LL>& M, vector<vector<LL> > &mix, vector<vector<LL> > &sum, int s = 0, int e = N - 1)
{
    if (s < 0 or e >= N or s > e) return make_pair(inf, inf);
    if (sum[s][e] != -1) return make_pair(mix[s][e], sum[s][e] % mod);
    if (s == e)
    {
        mix[s][e] = 0;
        sum[s][e] = M[s] % mod;
        return make_pair(mix[s][e], sum[s][e]);
    }
    LL smoke = inf;
    LL mval = inf;
    for (int i = s + 1; i <= e; i++)
    {
        pair<LL, LL> L = solve(M, mix, sum, s, i - 1);
        pair<LL, LL> R = solve(M, mix, sum, i, e);
        LL v1 = L.first + R.first + L.second * R.second;
        LL v2 = (L.second + R.second) % mod;
        if (v1 < smoke) smoke = v1, mval = v2;
    }
    mix[s][e] = smoke;
    sum[s][e] = mval % mod;
    return make_pair(mix[s][e], sum[s][e]);
}

int main()
{
    while (scanf("%d", &N) == 1)
    {
        vector<LL> M(N);
        for (auto &m: M) scanf("%lld", &m);
        vector<vector<LL> > mix(N, vector<LL> (N, -1));
        vector<vector<LL> > sum(N, vector<LL> (N, -1));
        printf("%lld\n", solve(M, mix, sum).first);
    }
    return 0;
}
