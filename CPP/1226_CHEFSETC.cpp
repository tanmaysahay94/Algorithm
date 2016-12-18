
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
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

int A[4];

bool solve()
{
    bool found = false;
    for (int bm = 1; not found and bm < 16; bm++)
    {
        int total = 0;
        for (int i = 0; i < 5 and (bm >> i); i++)
            if ((bm >> i) & 1)
                total += A[i];
        if (total == 0)
            found = true;
    }
    return found;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int T = 1; T <= t; T++)
    {
        for (int i = 0; i < 4; i++)
            scanf("%d", &A[i]);
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
