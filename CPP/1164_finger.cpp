
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

typedef unordered_set<char> uc_set;

int main()
{
    int n;
    scanf("%d", &n);
    string S;
    cin >> S;
    uc_set top;
    top.insert('1');
    top.insert('2');
    top.insert('3');
    uc_set bot;
    bot.insert('7');
    bot.insert('0');
    bot.insert('9');
    uc_set lef;
    lef.insert('1');
    lef.insert('4');
    lef.insert('7');
    lef.insert('0');
    uc_set rig;
    rig.insert('0');
    rig.insert('3');
    rig.insert('6');
    rig.insert('9');
    bool T(0), L(0), B(0), R(0);
    for (auto &s: S)
    {
        if (top.count(s)) T = 1;
        if (bot.count(s)) B = 1;
        if (lef.count(s)) L = 1;
        if (rig.count(s)) R = 1;
    }
    if (T and L and B and R) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
