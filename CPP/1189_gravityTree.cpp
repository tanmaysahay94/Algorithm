
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
const LL logn = 20;
vector<int> G[maxn];
LL S[maxn], S2[maxn], C[maxn], L[maxn], tin[maxn], tout[maxn];
LL dad[maxn][logn];
LL n, q;
LL timer = 0;

void dfs(int v = 1)
{
    C[v] = 1;
    if (G[v].empty())
    {
        S[v] = S2[v] = 0;
        return;
    }
    for (auto &u: G[v])
    {
        dfs(u);
        S[v] += C[u] + S[u];
        S2[v] += S2[u] + 2LL * S[u] + C[u];
        C[v] += C[u];
    }
}

void init(int v = 1, int p = 0, int lvl = 0)
{
    tin[v] = ++timer;
    dad[v][0] = p;
    L[v] = lvl;
    for (int i = 1; i < logn; i++)
        dad[v][i] = dad[dad[v][i - 1]][i - 1];
    for (auto &u: G[v])
        init(u, v, lvl + 1);
    tout[v] = ++timer;
}

bool anc(int u, int v)
{
    return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v)
{
    if (L[u] > L[v])
        swap(u, v);
    int d = L[v] - L[u];
    for (int i = 0; (1 << i) <= d; i++)
        if (d & (1 << i))
            v = dad[v][i];
    if (u == v)
        return u;
    for (int i = logn - 1; i >= 0; i--)
        if (dad[u][i] != dad[v][i])
            u = dad[u][i], v = dad[v][i];
    return dad[u][0];
}

int main()
{
    memset(S, 0, sizeof(S));
    memset(S2, 0, sizeof(S2));
    memset(C, 0, sizeof(C));
    memset(L, 0, sizeof(L));
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    memset(dad, 0, sizeof(dad));
    scanf("%lld", &n);
    for (int to = 2; to <= n; to++)
    {
        int from;
        scanf("%d", &from);
        G[from].push_back(to);
    }
    dfs();
    init();
    scanf("%lld", &q);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int dist = 0;
        if (anc(v, u))
            dist = L[v] - L[u];
        else
            dist = L[u] + L[v] - 2 * L[lca(u, v)];
        printf("%lld\n", S2[v] + 2LL * dist * S[v] + C[v] * dist * dist);
    }
    return 0;
}
