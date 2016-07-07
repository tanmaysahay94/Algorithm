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

int N, M, K;

const int maxn = 505;
const int maxk = 5005;
const int inf = INT_MAX;

vector<int> tim[maxk];
vector<pair<int, int> > G[maxn];

vector<int> dijk(int hour)
{
        vector<int> mindist(N, inf);
        mindist[0] = hour;
        set<pair<int, int> > pq;
        pq.insert(make_pair(hour, 0));
        while (pq.size())
        {
            pair<int, int> best = *(pq.begin()); pq.erase(pq.begin());
            int dist = best.first;
            int loc = best.second;
            mindist[loc] = min(mindist[loc], dist);
            for (auto &u: G[loc])
            {
                int dst = u.first, edge_num = u.second;
                int toAdd = tim[edge_num][dist % 24];
                if (dist + toAdd < mindist[dst])
                {
                    pq.erase(make_pair(mindist[dst], dst));
                    mindist[dst] = dist + toAdd;
                    pq.insert(make_pair(mindist[dst], dst));
                }
            }
        }
        for (auto &md: mindist)
            if (md == inf)
                md = -1;
            else
                md -= hour;
        return mindist;
}

int main()
{
        int T;
        scanf("%d", &T);
        for (int __T = 1; __T <= T; __T++)
        {
                printf("Case #%d: ", __T);
                scanf("%d%d%d", &N, &M, &K);
                for (int i = 0; i < N; i++)
                        G[i].clear();
                for (int i = 0; i < M; i++)
                {
                        int x, y;
                        scanf("%d%d", &x, &y);
                        x--; y--;
                        G[x].push_back(make_pair(y, i));
                        G[y].push_back(make_pair(x, i));
                        tim[i].clear();
                        for (int hr = 0; hr < 24; hr++)
                        {
                                int t_taken;
                                scanf("%d", &t_taken);
                                tim[i].push_back(t_taken);
                        }
                }
                vector<int> ans[24];
                for (int i = 0; i < 24; i++)
                        ans[i] = dijk(i);
                for (int i = 0; i < K; i++)
                {
                        int dst, hr;
                        scanf("%d%d", &dst, &hr);
                        printf("%d ", ans[hr][--dst]);
                }
                printf("\n");
        }
        return 0;
}
