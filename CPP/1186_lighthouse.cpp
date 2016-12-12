
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

char grid[55][55];

bool possible(int rad, int x, int y)
{
    for (int ydiff = 0; ydiff <= rad; ydiff++)
    {
        int xdiff = sqrt(rad * rad - ydiff * ydiff);
        for (int xloc = x - xdiff; xloc <= x + xdiff; xloc++)
            if (grid[xloc][y + ydiff] == '*' or grid[xloc][y - ydiff] == '*')
                return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", grid[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*') continue;
            int mx_rad = min(min(i, n - i - 1), min(j, n - j - 1));
            int k = ans;
            while (k <= mx_rad)
                if (possible(k, i, j)) k++;
                else break;
            ans = max(ans, k - 1);
        }
    printf("%d\n", ans);
    return 0;
}
