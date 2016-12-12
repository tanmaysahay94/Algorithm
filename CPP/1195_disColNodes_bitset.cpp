
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

const LL maxn = 1e5 + 5;
LL n;
vector<LL> level(maxn), C, G[maxn], vis(maxn), out(maxn);
bitset<maxn> B[maxn];

void dfs(int p = 0, int v = 1, int lvl = 0)
{
    if (vis[v]) return;
    vis[v] = 1;
    level[v] = lvl;
    B[v].set(C[v]);
    if (out[v] == 0) return;
    for (auto &u: G[v])
    {
        if (u == p) continue;
        dfs(v, u, lvl + 1);
        B[v] = B[v] | B[u];
    }
}

int main()
{
    scanf("%lld", &n);
    C = vector<LL> (n);
    set<LL> __S;
    for (int i = 1; i <= n; i++) 
    {
        LL &c = C[i];
        scanf("%lld", &c);
        __S.insert(c);
    }
    int cnt = 0;
    unordered_map<LL, LL> __M;
    for (auto &__s: __S) __M[__s] = ++cnt;
    for (auto &c: C) c = __M[c];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        out[u]++;
    }
    dfs();
    for (int i = 1; i <= n; i++)
        trace(i, C[i], B[i].count());
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        for (auto &j: G[i])
        {
            int u = i, v = j;
            if (level[u] > level[v]) swap(u, v);
        }
    printf("%lld\n", ans >> 1);
    return 0;
}
