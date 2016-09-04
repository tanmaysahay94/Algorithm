
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
    cin >> n;
    vector<string> v(n);
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (not possible)
            if (s[0] == s[1] and s[0] == 'O')
            {
                s[0] = s[1] = '+';
                possible = true;
            }
            else if (s[3] == s[4] and s[3] == 'O')
            {
                s[3] = s[4] = '+';
                possible = true;
            }
        v[i] = s;
    }
    if (possible)
    {
        cout << "YES\n";
        for (auto &vv: v)
            cout << vv << endl;
    }
    else
        cout << "NO\n";
    return 0;
}
