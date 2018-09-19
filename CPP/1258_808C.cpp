
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n, w;
    cin >> n >> w;
    vector<pair<LL, LL>> W(n), ans(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> W[i].first;
        W[i].second = i;
        ans[i].first = 0;
        ans[i].second = i;
    }
    LL curr = 0;
    for (int i = 0; i < n; i++)
    {
        LL val = 1 + (W[i].first - 1) / 2;
        curr += val;
        ans[i].first = val;
    }
    if (curr > w) 
    {
        cout << -1;
        return 0;
    }
    sort(W.rbegin(), W.rend());
    for (int i = 0; i < n; i++)
    {
        if (curr == w) break;
        LL rem = w - curr;
        LL canAdd = W[i].first - (1 + (W[i].first - 1) / 2);
        LL toAdd = min(rem, canAdd);
        curr += toAdd;
        ans[W[i].second].first += toAdd;
    }
    if (curr == w)
        for (auto &a: ans)
            cout << a.first << " ";
    else
        cout << "-1";
    return 0;
}
