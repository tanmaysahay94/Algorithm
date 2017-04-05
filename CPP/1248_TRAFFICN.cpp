
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

typedef long long LL;

class Graph {

    private:
        const int maxn = 1e4 + 5;
        const LL inf = 1e15;
        vector< vector< pair<int, LL>  >  > G, RG;
        vector<pair<pair<int, int>, LL> > special;
        int N;

    public:
        Graph() {
            G = RG = vector< vector<pair<int, LL> > > (maxn);
        }

        void init(int n) {
            N = n;
            for (int i = 1; i <= n; i++) {
                G[i].clear();
                RG[i].clear();
            }
            special.clear();
        }

        void inline add(int u, int v, LL w) {
            G[u].push_back(make_pair(v, w));
        }

        void inline addR(int u, int v, LL w) {
            RG[v].push_back(make_pair(u, w));
        }

        void inline splAdd(int u, int v, int w) {
            special.push_back(make_pair(make_pair(u, v), w));
        }

        vector<LL> dijk(int s, vector<vector<pair<int, LL> > >&gr) {
            vector<LL> ret(N + 1, inf);
            set<pair<LL, int> > minHeap;
            minHeap.insert(make_pair(0, s));
            ret[s] = 0;
            while (not minHeap.empty()) {
                pair<LL, int> best = *(minHeap.begin());
                minHeap.erase(minHeap.begin());
                LL dist = best.first;
                int from = best.second;
                for (auto &e: gr[from]) {
                    int to = e.first;
                    LL w = e.second;
                    if (ret[to] > ret[from] + w) {
                        if (ret[to] != inf) {
                            minHeap.erase(minHeap.find(make_pair(ret[to], to)));
                        }
                        ret[to] = ret[from] + w;
                        minHeap.insert(make_pair(ret[to], to));
                    }
                }
            }
            return ret;
        }

        LL solve(int s, int t) {
            vector<LL> ds = dijk(s, G);
            vector<LL> dt = dijk(t, RG);
            LL ret = ds[t];
            for (auto &e: special) {
                int u = e.first.first;
                int v = e.first.second;
                LL w = e.second;
                ret = min(ret, ds[u] + w + dt[v]);
                ret = min(ret, ds[v] + w + dt[u]);
            }
            if (ret >= inf) {
                return -1;
            }
            return ret;
        }
};

int main()
{
    Graph* graph = new Graph();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n, m, k, s, t;
        scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
        graph -> init(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            LL w;
            scanf("%d%d%lld", &u, &v, &w);
            graph -> add(u, v, w);
            graph -> addR(u, v, w);
        }
        for (int i = 0; i < k; i++)
        {
            int u, v;
            LL w;
            scanf("%d%d%lld", &u, &v, &w);
            graph -> splAdd(u, v, w);
        }
        printf("%lld\n", graph -> solve(s, t));
    }
    return 0;
}
