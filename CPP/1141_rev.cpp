
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
    int __T;
    scanf("%d", &__T);
    getchar();
    for (int T = 1; T <= __T; T++)
    {
        char c;
        string w;
        vector<string> ww;
        while ((c = getchar()) != '\n')
        {
            if (c == ' ')
            {
                ww.push_back(w);
                w = "";
            }
            else
                w.push_back(c);
        }
        ww.push_back(w);
        reverse(ww.begin(), ww.end());
        printf("Case #%d: ", T);
        cout << ww[0];
        for (int i = 1; i < (int) ww.size(); i++)
            cout << ' ' << ww[i];
        cout << '\n';
    }
    return 0;
}
