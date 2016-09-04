
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

LL solve(int n)
{
    int m = n << 1;
    vector<vector<LL> > V(m, vector<LL> (m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &V[i][j]);
    LL ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            LL mx = V[i][j];
            mx = max(mx, V[i][m - j - 1]);
            mx = max(mx, V[m - i - 1][j]);
            mx = max(mx, V[m - i - 1][m - j - 1]);
            ret += mx;
        }
    return ret;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}
