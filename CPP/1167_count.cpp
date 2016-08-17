
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
const LL mod = 1e9+7;

vector<int> G[26];

LL cal(int i)
{
    LL n = G[i].size() % mod;
    LL ret = n;
    for (int i = 1; i < 4; i++)
    {
        ret *= (n - i);
        ret /= (i + 1);
        ret %= mod;
    }
    return ret;
}

LL _cal(LL len)
{
    LL ret = (len * (len - 1)) / 2;
    ret %= mod;
    return ret;
}

LL count(int _i, int _j)
{
    LL ret = 0;
    for (int i = 0; i < (int) G[_i].size(); i++)
        for (int j = i + 1; j < (int) G[_i].size(); j++)
        {
            LL start = upper_bound(G[_j].begin(), G[_j].end(), G[_i][i]) - G[_j].begin();
            LL end   = upper_bound(G[_j].begin(), G[_j].end(), G[_i][j]) - G[_j].begin() - 1;
            LL len = end - start + 1;
            ret += _cal(len);
            ret %= mod;
        }
    return ret;
}

int main()
{
    string S;
    cin >> S;
    LL ans = 0;
    for (int i = 0; i < (int) S.size(); i++)
        G[S[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (i == j)
            {
                LL val = cal(i);
                ans = (ans + val) % mod;
            }
            else
            {
                if (G[i].size() > 1 and G[j].size() > 1)
                {
                    LL val = count(i, j);
                    ans = (ans + val) % mod;
                }
            }
    printf("%lld\n", ans);
    return 0;
}
