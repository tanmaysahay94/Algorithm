
#include <bits/stdc++.h>
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
const LL inf = LLONG_MAX;

int main()
{
    int n;
    scanf("%d", &n);
    vector<LL> dist(n + 1, inf), G[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int to;
        scanf("%d", &to);
        G[i].push_back(to);
    }
    queue<pair<LL, LL> > Q;
    Q.push(make_pair(1, 0));
    while (Q.size())
    {
        pair<LL, LL> f = Q.front();
        Q.pop();
        LL loc = f.first, ans = f.second;
        if (dist[loc] != inf) continue;
        dist[loc] = min(dist[loc], ans);
        if (loc != n) Q.push(make_pair(loc + 1, ans + 1));
        if (loc != 1) Q.push(make_pair(loc - 1, ans + 1));
        for (auto &dst: G[loc])
            if (dist[dst] == inf)
                Q.push(make_pair(dst, ans + 1));
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", dist[i]);
    printf("\n");
    return 0;
}
