
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

template <typename tp> class BIT
{
    private:
        int n;
        vector<tp> T;
    public:
        BIT(int _n)
        {
            n = _n + 1;
            T.resize(n);
            fill(T.begin(), T.end(), 0);
        }
        void update(int idx, tp val)
        {
            while (idx < n)
            {
                T[idx] += val;
                idx += (idx&(-idx));
            }
        }
        tp query(int idx)
        {
            tp ret = 0;
            while (idx)
            {
                ret += T[idx];
                idx -= (idx&(-idx));
            }
            return ret;
        }
        tp query(int l, int r)
        {
            return query(r) - query(l - 1);
        }
};

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        printf("Case #%d:\n", T);
        int n, m;
        scanf("%d%d", &n, &m);
        BIT<double> bit(n);
        for (int i = 1; i <= n; i++)
        {
            double val;
            scanf("%lf", &val);
            bit.update(i, log10(val));
        }
        for (int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%.6lf\n", pow(10.0, bit.query(++l, ++r) / (r - l + 1)));
        }
    }
    return 0;
}
