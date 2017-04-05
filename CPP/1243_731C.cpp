#include "bits/stdc++.h"
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

const int maxn = 2e5 + 5;
vector<int> G[maxn];
int V[maxn], C[maxn];

void dfs(int v, unordered_map<int, int> &counts)
{
    if (V[v])
        return;
    V[v] = 1;
    counts[C[v]]++;
    for (auto &u: G[v])
        dfs(u, counts);
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        G[l].push_back(r);
        G[r].push_back(l);
    }
    int ans = 0;
    memset(V, 0, sizeof(V));
    for (int i = 1; i <= n; i++)
        if (not V[i] and G[i].size())
        {
            unordered_map<int, int> counts;
            dfs(i, counts);
            int mx = 0, tot = 0;
            for (auto &c: counts)
            {
                mx = max(mx, c.second);
                tot += c.second;
            }
            ans += tot - mx;
        }
    printf("%d\n", ans);
    return 0;
}
