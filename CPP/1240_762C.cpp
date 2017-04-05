
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
    string a, b;
    cin >> a >> b;
    int forward, backward, v1 = 0, v2 = b.size() - 1;
    int l_fwd, l_bwd;
    for (int forward = 0, backward = a.size() - 1; a[forward] and a[backward]; forward++, backward--)
    {
        if (v1 < (int) b.size() and a[forward] == b[v1]) l_fwd = forward, v1++;
        if (v2 >= 0 and a[backward] == b[v2]) l_bwd = backward, v2--;
    }
    int l1 = v1, l2 = b.size() - 1 - v2;
    if (l1 == 0 and l2 == 0)
        cout << "-";
    else
    {
        if (l1 == b.size() or l2 == b.size())
            cout << b;
        else
        {
            if (l_fwd <= l_bwd)
            {
                if (l_fwd == l_bwd)
                    v2++;
                for (int i = 0; i < v1; i++)
                    cout << b[i];
                for (int i = v2 + 1; b[i]; i++)
                    cout << b[i];
            }
            else
            {
                if (l1 > l2)
                    for (int i = 0; i < v1; i++)
                        cout << b[i];
                else
                    for (int i = v2 + 1; b[i]; i++)
                        cout << b[i];
            }
        }
    }
    cout << '\n';
    return 0;
}
