
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

typedef long long LL;

const int TLIM = 4e5 + 100;
const int maxn = 1e5 + 25;
int arr[maxn], T[TLIM];

void build(int node, int left, int right)
{
    if (left == right)
    {
        T[node] = arr[left];
        return;
    }
    int m = (left + right) / 2;
    build(2 * node, left, m);
    build(2 * node + 1, m + 1, right);
    T[node] = T[2 * node] | T[2 * node + 1];
}

int query(int node, int qleft, int qright, int segleft, int segright)
{
    if (qleft <= segleft and segright <= qright) return T[node];
    int _smid = (segleft + segright) / 2;
    if (_smid >= qright) return query(2 * node, qleft, qright, segleft, _smid);
    else if (_smid < qleft) return query(2 * node + 1, qleft, qright, _smid + 1, segright);
    return query(2 * node, qleft, _smid, segleft, _smid) | query(2 * node + 1, _smid + 1, qright, _smid + 1, segright);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int T = 1; T <= t; T++)
    {
        int N, K;
        LL val = 0;
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);
        build(1, 1, N);
        int i = 1, j = 1;
        while (i <= N and j <= N)
        {
            if (query(1, i, j, 1, N) >= K) val += N - j + 1, i++;
            else j++;
            if (j < i) j = max(j, i);
        }
        printf("%lld\n", val);
    }
    return 0;
}
