
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

LL maxn = 3.17e7;
vector<bool> isprime(maxn, 1);
vector<LL> primes;
unordered_map<LL, bool> DP;

void sieve()
{
    for (int i = 2; i < maxn; i++)
        if (isprime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < maxn; j += i)
                isprime[j] = 0;
        }
}

int digSum(LL n)
{
    int ret = 0;
    while (n)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

unordered_map<LL, LL> factorize(LL n)
{
    unordered_map<LL, LL> ret;
    for (auto &p: primes)
    {
        if (n == 1)
            break;
        if (n % p)
            continue;
        int cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }
        ret[p] = cnt;
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

LL fastPow(LL a, LL b)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

bool solve(LL n, unordered_map<LL, LL> pf)
{
    if (DP.count(n))
        return DP[n];
    if (n == 1)
        return DP[n] = false;
    if (isprime[digSum(n)])
        return DP[n] = false;
    bool ret = false;
    for (auto p: pf)
    {
        LL base = p.first, power = p.second;
        unordered_map<LL, LL> tmp = pf;
        tmp.erase(base);
        ret |= not solve(n / fastPow(base, power), tmp);
    }
    return DP[n] = ret;
}

bool f(LL n)
{
    if (DP.count(n))
        return DP[n];
    if (isprime[digSum(n)])
        return DP[n] = false;
    unordered_map<LL, LL> pf = factorize(n);
    bool ret = solve(n, pf);
    DP[n] = ret;
    return DP[n];
}

int main()
{
    sieve();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        LL N;
        scanf("%lld", &N);
        printf("Case #%d: %s\n", T, f(N) ? "Laurence" : "Seymour");
    }
    return 0;
}
