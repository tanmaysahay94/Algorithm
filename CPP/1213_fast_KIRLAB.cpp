
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
const int mxval = 1e7 + 2;
const int maxn = 1e5 + 2;
int S[mxval], cnt[mxval];
vector<int> fac[mxval];

void init()
{
    for (int i = 2; i < mxval; i++)
        if (!S[i])
            for (int j = i; j < mxval; j += i)
                fac[j].push_back(i), S[j] = 1;
}

int upd(int val)
{
    int mxcnt = 0;
    for (auto &f: fac[val])
        mxcnt = max(mxcnt, cnt[f]);
    mxcnt++;
    for (auto &f: fac[val])
        cnt[f] = mxcnt;
    return mxcnt;
}

int main()
{
    init();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        memset(cnt, 0, sizeof(cnt));
        int N;
        scanf("%d", &N);
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int val;
            scanf("%d", &val);
            ans = max(ans, upd(val));
        }
        printf("%d\n", ans);
    }
    return 0;
}
