
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
        printf("Case #%d: ", T);
        double p, x, y;
        scanf("%lf%lf%lf", &p, &x, &y);
        x -= 50, y -=50;
        if (x * x + y * y > 2500)
        {
            printf("white\n");
            continue;
        }
        double x_ = y, y_ = -x;
        x = x_, y = -y_;
        double degree = p * 3.6;
        double angle = atan2(y, x) * 180.0 / M_PI;
        if (angle < 0)
            angle += 360;
        if (angle <= degree)
            printf("black\n");
        else
            printf("white\n");
    }
    return 0;
}
