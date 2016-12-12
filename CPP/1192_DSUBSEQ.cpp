
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
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char S[maxn];
int last[26];
LL ans[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 26; i++) last[i] = -1;
        scanf("%s", S);
        int len = strlen(S);
        ans[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            ans[i] = 2 * ans[i - 1];
            ans[i] %= mod;
            if (last[S[i - 1] - 'A'] != -1)
            {
                ans[i] -= ans[last[S[i - 1] - 'A']];
                ans[i] %= mod;
                if (ans[i] < 0) ans[i] += mod;
            }
            last[S[i - 1] - 'A'] = i - 1;
        }
        printf("%lld\n", ans[len]);
    }
    return 0;
}
