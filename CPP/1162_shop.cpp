
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

const double eps = 1e-15;

double f(vector<double> &V, double r)
{
    double ret = 0;
    double p = 1;
    for (int i = (int) V.size() - 1; i >= 0; i--)
    {
        ret += V[i] * p;
        p *= (1 + r);
    }
    return ret;
}

double bsearch(vector<double>& V)
{
    double lo = -1, hi = 1;
    while (hi - lo > eps)
    {
        double m = (hi + lo) / 2;
        if (f(V, m) < eps)
            hi = m;
        else
            lo = m;
    }
    return lo;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int M;
        scanf("%d", &M);
        vector<double> V(M + 1);
        for (auto &v: V)
            scanf("%lf", &v);
        V[0] *= -1;
        double ans = bsearch(V);
        if ((ans < 0 and -eps < ans) or (ans > 0 and ans < eps)) ans = 0;
        printf("Case #%d: %.9lf\n", T, ans);
    }
    return 0;
}
