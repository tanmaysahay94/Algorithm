
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
    LL n, k;
    cin >> n >> k;
    LL lim = sqrt(n);
    vector<LL> V;
    for (int i = 1; i <= lim; i++)
        if (n % i == 0)
        {
            V.push_back(i);
            if (i != n / i)
                V.push_back(n / i);
        }
    sort(V.begin(), V.end());
    if (k > (int) V.size())
        cout << -1;
    else
        cout << V[k - 1];
    cout << endl;
    return 0;
}
