
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
typedef pair<pair<LL, LL>, LL> road;    // pair<pair<weight, dest>, idx>

class Solution
{
    private:
        int N, M;
        vector<vector<road> > G;
    public:
        Solution() {}
        void input()
        {
            scanf("%d%d", &N, &M);
            G = vector<vector<road> > (N, vector<road> ());
            for (int i = 0; i < M; i++)
            {
                int U, V, C;
                scanf("%d%d%d", &U, &V, &C);
                G[U].push_back(make_pair(make_pair(C, V), i));
                G[V].push_back(make_pair(make_pair(C, U), i));
            }
        }
        vector<LL> solve()
        {
            unordered_set<LL> useless;
            for (int i = 0; i < M; i++)
                useless.insert(i);
            for (int i = 0; i < N; i++)
            {
                unordered_set<LL> useful = dijk(i);
                for (auto &u: useful)
                    useless.erase(u);
            }
            vector<LL> v;
            for (auto &r: useless)
                v.push_back(r);
            sort(v.begin(), v.end());
            return v;
        }
        unordered_set<LL> dijk(int src)
        {
            vector<unordered_set<LL> > VUS(N);
            unordered_set<LL> useful;
            set<road> pq;
            vector<LL> ans(N, LLONG_MAX);
            ans[src] = 0;
            pq.insert(make_pair(make_pair(0, src), -1));
            while (pq.size())
            {
                road best = *(pq.begin()); pq.erase(pq.begin());
                LL dist = best.first.first;
                LL loc = best.first.second;
                LL rnum = best.second;
                if (dist < ans[loc])
                {
                    ans[loc] = dist;
                    VUS[loc].clear();
                    VUS[loc].insert(rnum);
                }
                else if (dist == ans[loc])
                    VUS[loc].insert(rnum);
                for (auto &u: G[loc])
                {
                    LL _dist = u.first.first;
                    LL _loc = u.first.second;
                    LL _rnum = u.second;
                    if (_dist + dist < ans[_loc])
                    {
                        VUS[_loc].clear();
                        VUS[_loc].insert(_rnum);
                        ans[_loc] = dist + _dist;
                        pq.insert(make_pair(make_pair(_dist + dist, _loc), _rnum));
                    }
                    else if (_dist + dist == ans[_loc])
                        VUS[_loc].insert(_rnum);
                }
            }
            for (auto &u: VUS)
                for (auto &v: u)
                    useful.insert(v);
            return useful;
        }
};

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        printf("Case #%d:\n", T);
        Solution S;
        S.input();
        vector<LL> useless = S.solve();
        for (auto &u: useless)
            printf("%lld\n", u);
    }
    return 0;
}
