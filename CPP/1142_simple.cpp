
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

class Solution
{
    private:
        int n;
        vector<LL> v1, v2;
    public:
        Solution(int _n)
        {
            n = _n;
            v1.reserve(n);
            v2.reserve(n);
        }
        void input()
        {
            for (int i = 0; i < n; i++)
                scanf("%lld", &v1[i]);
            for (int i = 0; i < n; i++)
                scanf("%lld", &v2[i]);
        }
        LL solve()
        {
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end(), greater<LL> ());
            LL ans = 0;
            for (int i = 0; i < n; i++)
                ans += v1[i] * v2[i];
            return ans;
        }
};

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n;
        scanf("%d", &n);
        Solution S(n);
        S.input();
        printf("%lld\n", S.solve());
    }
    return 0;
}
