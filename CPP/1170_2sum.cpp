
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

int main()
{
    LL target;
    scanf("%lld", &target);
    int n;
    scanf("%d", &n);
    vector<LL> V(n);
    for (auto &v: V)
        scanf("%lld", &v);
    sort(V.begin(), V.end());
    bool found = false;
    int i = 0, j = n - 1;
    while (i < j and not found)
    {
        LL sum = V[i] + V[j];
        if (sum == target) found = true;
        else if (sum < target) i++;
        else j--;
    }
    printf("%d", found);
    return 0;
}
