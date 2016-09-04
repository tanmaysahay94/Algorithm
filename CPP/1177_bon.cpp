
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
    int __T, K;
    scanf("%d%d", &__T, &K);
    vector<double> C(__T);
    for (int T = 0; T < __T; T++)
        scanf("%lf", &C[T]);
    double actual = 0;
    for (int i = 0; i < __T; i++)
        if (i != K)
            actual += C[i];
    actual = actual / 2;
    double charge;
    scanf("%lf", &charge);
    if (charge > actual)
        printf("%d", (int) (charge - actual));
    else
        printf("Bon Appetit");
    return 0;
}
