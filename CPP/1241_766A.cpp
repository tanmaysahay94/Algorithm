
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
    if (a == b) { cout << -1 << endl; return 0; }
    if (a.size() > b.size()) cout << a.size();
    else cout << b.size();cout<<endl;
    /*
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
    }
    */
    return 0;
}
