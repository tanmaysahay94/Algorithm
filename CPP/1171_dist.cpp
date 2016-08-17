
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

typedef pair<double, double> point;

double f(point& a, point& b)
{
    double xdiff = a.first - b.first;
    xdiff *= xdiff;
    double ydiff = a.second - b.second;
    ydiff *= ydiff;
    return sqrt(xdiff + ydiff);
}

int main()
{
    point origin;
    scanf("%lf%lf", &origin.first, &origin.second);
    int n;
    scanf("%d", &n);
    double ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        point taxi;
        double vel;
        scanf("%lf%lf%lf", &taxi.first, &taxi.second, &vel);
        ans = min(ans, f(origin, taxi) / vel);
    }
    printf("%.9lf\n", ans);
    return 0;
}
