
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
set<LL> factors, exists;

int main()
{
    LL N;
    scanf("%lld", &N);
    for (LL i = 1; i * i <= N; i++)
        if (N % i == 0)
        {
            factors.insert(i);
            factors.insert(N / i);
        }
    for (auto &i: factors)
        for (auto &j: factors)
            if (i * j >= N) break;
            else if (not factors.count(i * j)) exists.insert(i * j);
    printf("%d\n", (int) exists.size());
    return 0;
}
