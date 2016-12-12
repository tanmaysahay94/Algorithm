
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

class DSU
{
    public:
        vector<LL> size, parent;
        int N;
        DSU(int n)
        {
            N = n;
            size = vector<LL> (N, 1);
            parent = vector<LL> (N);
            for (int i = 0; i < N; i++)
                parent[i] = i;
        }
        void merge(int a, int b)
        {
            a = rep(a);
            b = rep(b);
            if (size[a] < size[b])
                swap(a, b);
            size[a] += size[b];
            size[b] = 0;
            parent[b] = a;
        }
        LL rep(LL a)
        {
            if (parent[a] == a)
                return a;
            return parent[a] = rep(parent[a]);
        }
};

int main()
{
    LL n, m;
    scanf("%lld%lld", &n, &m);
    DSU dsu(n);
    vector<pair<LL, pair<LL, LL> > > edges;
    for (int i = 0; i < m; i++)
    {
        LL u, v, status, wt;
        scanf("%lld%lld%lld", &u, &v, &status);
        u--; v--;
        if (status)
        {
            scanf("%lld", &wt);
            edges.push_back(make_pair(wt, make_pair(u, v)));
        }
        else
            dsu.merge(u, v);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (dsu.size[i])
            count++;
    LL ans = 0;
    sort(edges.begin(), edges.end());
    for (auto &e: edges)
    {
        if (count == 1)
            break;
        LL wt = e.first;
        LL u = e.second.first;
        LL v = e.second.second;
        if (dsu.rep(u) == dsu.rep(v))
            continue;
        ans += wt;
        dsu.merge(u, v);
        count--;
    }
    printf("%lld\n", ans);
    return 0;
}
