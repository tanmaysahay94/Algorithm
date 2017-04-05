
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

unordered_map<char, int> f(string& S)
{
    unordered_map<char, int> ret;
    for (auto &s: S) ret[s]++;
    return ret;
}

int main()
{
    string target("Bulbasaur");
    string in;
    cin >> in;
    unordered_map<char, int> u1, u2;
    u1 = f(target);
    u2 = f(in);
    int ans = INT_MAX;
    for (auto &u: u1)
        ans = min(ans, u2[u.first] / u.second);
    cout << ans << endl;
    return 0;
}
