
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

class Solution
{
    public:
        LL n, k;
        vector<LL> treats, people;
        Solution(LL _n, LL _k): n(_n), k(_k) 
        {
            treats.resize(n);
            people.resize(n);
        }
        void input()
        {
            for (int i = 0; i < n; i++)
                cin >> treats[i] >> people[i];
        }
        LL solve()
        {
            vector<pair<LL, LL> > V(n);
            for (int i = 0; i < n; i++)
                V[i] = make_pair(
                        min(2 * treats[i], people[i]) - min(treats[i], people[i]),
                        i
                        );
            sort(V.rbegin(), V.rend());
            LL ans = 0;
            for (int i = 0; i < k; i++)
            {
                int idx = V[i].second;
                ans += min(2 * treats[idx], people[idx]);
            }
            for (int i = k; i < n; i++)
            {
                int idx = V[i].second;
                ans += min(treats[idx], people[idx]);
            }
            return ans;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n, k;
    cin >> n >> k;
    Solution S(n, k);
    S.input();
    cout << S.solve() << endl;
    return 0;
}
