
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int __T;
    cin >> __T;
    for (int T = 1; T <= __T; T++)
    {
        int len;
        string report;
        cin >> len >> report;
        int count = 0;
        for (auto &c: report)
        {
            if (c == 'H')
                count++;
            else if (c == 'T')
                count--;
            if (count < 0 or count > 1)
                break;
        }
        if (not count)
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
    return 0;
}
