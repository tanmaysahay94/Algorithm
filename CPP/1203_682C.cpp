
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

vector<LL> a(maxn), S(maxn, 1);
vector<vector<pair<LL, LL> > > G(maxn, vector<pair<LL, LL> > ());

void dfs1(int root = 0, int parent = -1)
{
    trace(root, parent);
    if (G[root].size() == 1 and G[root][0].first == parent)
        return;
    for (auto &child: G[root])
    {
        if (child.first == parent) continue;
        dfs1(child.first, root);
        S[root] += S[child.first];
    }
}

void dfs2(int& ans, int root = 0, int parent = -1, int weight = 0)
{
    trace(ans, root, parent, weight, a[root], S[root]);
    if (root)
        if (weight > a[root])
        {
            ans += S[root];
            return;
        }
    for (auto &child: G[root])
    {
        if (child.first == parent) continue;
        if (child.second <= a[child.first]) dfs2(ans, child.first, root, weight + child.second);
        else ans += S[child.first];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i < n; i++)
    {
        LL p, c;
        scanf("%lld%lld", &p, &c);
        G[p - 1].push_back(make_pair(i, c));
        G[i].push_back(make_pair(p - 1, c));
    }
    dfs1();
    return 0;
}
