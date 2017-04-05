
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
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int n;
        scanf("%d", &n);
        int toPay = 0;
        int lastPaid = -1;
        for (int i = 0; i < n; i++)
        {
            toPay += 1000;
            int val;
            scanf("%d", &val);
            if (val)
            {
                toPay -= 1000;
                if (lastPaid != i - 1)
                    toPay += 100;
                lastPaid++;
            }
            else
                toPay += 100;
        }
        printf("%d\n", toPay);
    }
    return 0;
}
