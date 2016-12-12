
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>
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
    double x, y, a, b;
    scanf("%lf%lf%lf%lf", &x, &y, &a, &b);
    double b_2 = (a * a + b * b) / (1 + ((b * b) / (a * a)));
    double b_  = sqrt(b_2);
    double a_  = -b * b_ / a; 
    double n = (b * x - a * y) / (b * a_ - a * b_);
    double k = (x - n * a_) / a;
    printf("%lf\n%lf\n", k, n);
    return 0;
}
