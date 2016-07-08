
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

bool cmp(const pair<LL, string> &l, const pair<LL, string> &r)
{
    if (l.first == r.first)
        return l.second < r.second;
    return l.first > r.first;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        printf("Case #%d:\n", T);
        LL P;
        scanf("%lld", &P);
        vector<LL> S(P);
        for (auto &s: S)
            scanf("%lld", &s);
        LL N;
        scanf("%lld", &N);
        unordered_map<string, vector<LL> > u_map;
        for (int i = 0; i < N; i++)
        {
            LL W;
            scanf("%d", &W);
            for (int rank = 0; rank < P; rank++)
            {
                string name;
                cin >> name;
                u_map[name].push_back(W * S[rank]);
            }
        }
        LL M;
        scanf("%lld", &M);
        for (auto &u: u_map)
            sort(u.second.begin(), u.second.end(), greater<LL>());
        vector<pair<LL, string> > F;
        for (auto &u: u_map)
        {
            LL score = 0;
            for (int i = 0; i < min(M, (LL) u.second.size()); i++)
                score += u.second[i];
            F.push_back(make_pair(score, u.first));
        }
        sort(F.begin(), F.end(), cmp);
        LL rank = 1;
        cout << rank << ": " << F[0].second << '\n';
        for (int i = 1; i < (int) F.size(); i++)
        {
            if (F[i].first < F[i - 1].first)
                rank = i + 1;
            cout << rank << ": " << F[i].second << '\n';
        }
    }
    return 0;
}
