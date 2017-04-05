
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

pair<LL, LL> f1(LL a, LL b, LL c, vector<LL>& U, vector<LL>& P)
{
    LL count = 0, sum = 0;
    int i, j, k;
    for (i = 0; i < min(a, (LL) U.size()); i++)
        count++, sum += U[i];
    for (j = 0; j < min(b, (LL) P.size()); j++)
        count++, sum += P[j];
    for (k = 0; k < c and i < U.size() and j < P.size(); k++)
        if (U[i] < P[j])
            count++, sum += U[i++];
        else
            count++, sum += P[j++];
    for (; k < c and i < U.size(); k++, i++)
        count++, sum += U[i];
    for (; k < c and j < P.size(); k++, j++)
        count++, sum += P[j];
    return make_pair(count, sum);
}

int main()
{
    LL a, b, c, n;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
    vector<LL> U, P;
    char type[5];
    for (int i = 0; i < n; i++)
    {
        LL val;
        scanf("%lld%s", &val, type);
        if (type[0] == 'U') U.push_back(val);
        else P.push_back(val);
    }
    sort(U.begin(), U.end());
    sort(P.begin(), P.end());
    pair<LL, LL> ans = f1(a, b, c, U, P);
    printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}
