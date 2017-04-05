
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

int main()
{
    LL ans = 0;
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        string s;
        cin >> s;
        if      (s == "Tetrahedron")    ans += 4;
        else if (s == "Cube")           ans += 6;
        else if (s == "Octahedron")     ans += 8;
        else if (s == "Dodecahedron")   ans += 12;
        else                            ans += 20;
    }
    printf("%lld\n", ans);
    return 0;
}
