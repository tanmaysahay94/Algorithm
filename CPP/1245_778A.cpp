
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

bool ok(string& big, string& small, vector<int>& loc, int idx)
{
    vector<int> active(loc.size(), 1);
    for (int i = 0; i <= idx; i++)
        active[loc[i]] = 0;
    int match = 0;
    for (int i = 0; i < (int) big.size() and match < (int) small.size(); i++)
        if (active[i] and small[match] == big[i])
            match++;
    return match == (int) small.size();
}

int solve(string& big, string& small, vector<int>& loc)
{
    int lo = -1, hi = loc.size();
    while (lo + 1 < hi)
    {
        int mi = lo + (hi - lo) / 2;
        if (ok(big, small, loc, mi))
            lo = mi;
        else
            hi = mi;
    }
    return lo;
}

int main()
{
    string big, small;
    cin >> big >> small;
    vector<int> loc(big.size());
    for (auto &l: loc)
    {
        cin >> l;
        l--;
    }
    cout << 1 + solve(big, small, loc) << endl;
    return 0;
}
