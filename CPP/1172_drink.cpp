
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

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> X(n);
    for (auto &x: X)
        scanf("%d", &x);
    sort(X.begin(), X.end());
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int val;
        scanf("%d", &val);
        auto it = upper_bound(X.begin(), X.end(), val);
        it--;
        int idx = it - X.begin() + 1;
        printf("%d\n", idx);
    }
    return 0;
}
