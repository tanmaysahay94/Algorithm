
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
const LL maxn = 1e6 + 1;

vector<pair<LL, LL>> pFac[maxn];
int sieve[maxn];

void init()
{
    memset(sieve, 0, sizeof(sieve));
    for (int i = 2; i < maxn; i++)
    {
        if (sieve[i]) continue;
        for (int j = i; j < maxn; j += i)
        {
            int num = j;
            int cnt = 0;
            while (num % i == 0) num /= i, cnt++;
            pFac[j].push_back(make_pair(i, cnt));
            sieve[j] = 1;
        }
    }
}

int main()
{
    init();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n;
        scanf("%d", &n);
        unordered_map<LL,LL> u_map;
        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            for (auto &p: pFac[val])
                u_map[p.first] += p.second;
        }
        LL ans = 1;
        for (auto &u: u_map)
            ans *= u.second + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
