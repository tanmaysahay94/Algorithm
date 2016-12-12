
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
const int maxn = 1e5 + 5;
const LL mxval = 1e6 + 6;
int A[maxn], DP[maxn], pos[mxval], S[mxval];
vector<int> fac[mxval];

void init()
{
    for (int i = 2; i < mxval; i++)
        if (S[i] == 0)
            for (int j = i; j < mxval; j += i)
                fac[j].push_back(i), S[j] = 0;
}

int get(int idx)
{
    LL val = A[idx];
    int ret = -1;
    for (auto &f: fac[val])
    {
        ret = max(ret, pos[f]);
        pos[f] = idx;
    }
    return ret;
}

int main()
{
    memset(S, 0, sizeof(S));
    init();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N;
        scanf("%d", &N);
        memset(pos, -1, sizeof(pos));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
            DP[i] = 1;
        }
        for (int i = 1; i < N; i++)
        {
            int last = get(i);
            int gcd = __gcd(A[i], A[i - 1]);
            if (gcd > 1) continue;
            DP[i] = min(DP[i - 1] + 1, i - last);
        }
        int ans = -1;
        for (int i = 0; i < N; i++) ans = max(ans, DP[i]);
        printf("%d\n", ans == 1 ? -1 : ans);
    }
    return 0;
}
