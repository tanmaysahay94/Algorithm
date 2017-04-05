
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
    int n;
    cin >> n;
    vector<LL> V(n);
    for (auto &v: V) cin >> v;
    sort(V.begin(), V.end());
    bool found = false;
    for (int i = 1; i + 1 < n and not found; i++)
    {
        LL a = V[i - 1], b = V[i], c = V[i + 1];
        if (a + b > c and b + c > a and c + a > b)
            found = true;
    }
    if (found) cout << "YES\n";
    else cout << "NO\n";
    /*
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
    }
    */
    return 0;
}
