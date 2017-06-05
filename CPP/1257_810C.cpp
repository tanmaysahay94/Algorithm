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

LL mod = 1e9 + 7;

inline LL fastPowMod(LL base, LL pow, LL MOD = mod)
{
    LL ret = 1;
    while (pow)
    {
        if (pow & 1)
            ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        pow >>= 1;
    }
    return ret;
}

inline LL add(LL a, LL b, LL MOD = mod)
{
    a %= MOD;
    b %= MOD;
    a = (a + b) % MOD;
    if (a < 0)
        a += MOD;
    return a;
}

inline LL mul(LL a, LL b, LL MOD = mod)
{
    a %= MOD;
    b %= MOD;
    a = (a * b) % MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n;
    cin >> n;
    vector<LL> X(n);
    for (auto &x: X) cin >> x;
    sort(X.begin(), X.end());
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << X.back() - X.front() << endl;
        return 0;
    }
    vector<LL> pre(X), post(X);
    for (int i = 1, j = n - 2; i < n; i++, j--)
    {
        pre[i] += pre[i - 1];
        post[j] += post[j + 1];
    }
    LL ans = 0;
    for (LL s1 = 0, s2 = n - 2; s1 < s2; s1++, s2--)
    {
        ans = add(ans, 
                mul(post[s2 + 1] - pre[s1], 
                    fastPowMod(2, s1)
                   )
                );
        ans = add(ans,
                mul(post[s2 + 1] - pre[s1],
                    fastPowMod(2, s2)
                   )
                );
    }
    if (n % 2 == 0)
    {
        int s2 = n / 2;
        int s1 = s2 - 1;
        ans = add(ans,
                mul(post[s2] - pre[s1],
                    fastPowMod(2, s1)
                    )
                );
    }
    cout << ans << endl;
    return 0;
}
