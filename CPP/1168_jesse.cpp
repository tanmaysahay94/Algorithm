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
const LL maxn = 2e5 + 5;

LL N[maxn];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &N[i]);
    for (int i = 0; i < d; i++)
    {
        LL D;
        scanf("%lld", &D);
        bool found = false;
        unordered_map<LL, LL> day_idx;
        day_idx[N[1]] = 1;
        int start, end;
        int diff = INT_MAX;
        for (int day = 2; day <= n; day++)
        {
            day_idx[N[day]] = day;
            auto it = day_idx.find(N[day] - D);
            if (it == day_idx.end()) continue;
            found = true;
            int tmp = day - it -> second;
            if (tmp < diff)
                diff = tmp, end = day, start = it -> second;
        }
        if (found) printf("%d %d\n", start, end);
        else printf("-1\n");
    }
    return 0;
}
