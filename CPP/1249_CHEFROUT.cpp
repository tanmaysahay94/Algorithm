
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
    unordered_map<char, int> U;
    U['C'] = 0;
    U['E'] = 1;
    U['S'] = 2;
    for (int T = 1; T <= __T; T++)
    {
        string S, ans = "yes";
        cin >> S;
        for (int i = 1; i < (int) S.size(); i++)
        {
            char a = S[i - 1], b = S[i];
            int p = U[a], q = U[b];
            int diff = q - p;
            if (diff < 0)
            {
                ans = "no";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
