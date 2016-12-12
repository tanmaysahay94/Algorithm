#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>
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

const LL maxval = 1e7 + 7;
const LL lim = ceil(sqrt(maxval));

vector<LL> primes;
int sieve[3200];

void init()
{
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < maxval; i++)
        if (!sieve[i])
        {
            if (i * i <= maxval)
                primes.push_back(i);
            for (int j = 2 * i; j * j < maxval; j += i)
                sieve[j] = 1;
        }
}

void initDS(unordered_map<LL, LL>& mp)
{
    if (mp.size())
        for (auto &p: mp)
            p.second = 0;
    else
        for (auto &p: primes)
            mp[p] = 0;
}

void alter(unordered_map<LL, LL>& mp, LL val)
{
    LL toStore = INT_MIN;
    vector<LL> toUpd;
    for (int i = 0; i < (int) primes.size() and val > 1; i++)
        if (val % primes[i] == 0)
        {
            toUpd.push_back(primes[i]);
            toStore = max(toStore, mp[primes[i]]);
            while (val % primes[i] == 0)
                val /= primes[i];
        }
    if (val > 1)
    {
        if (mp.find(val) == mp.end())
            mp[val] = 0;
        toStore = max(toStore, mp[val]);
        mp[val] = toStore + 1;
    }
    for (auto &t: toUpd)
        mp[t] = toStore + 1;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    unordered_map<LL, LL> mp;
    while (T--)
    {
        initDS(mp);
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            LL val;
            scanf("%lld", &val);
            alter(mp, val);
        }
        LL ans = 0;
        for (auto &m: mp)
            ans = max(ans, m.second);
        printf("%lld\n", ans);
//        printf("%lld\n", ans > 1 ? ans : ans);
    }
    return 0;
}
