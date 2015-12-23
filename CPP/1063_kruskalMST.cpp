#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 3005;

unordered_map<LL, LL> eds[maxn];    // key: location, value: weight
vector<int> done(maxn, 0);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        LL x, y, S;
        cin >> x >> y >> S;
        x--, y--;
        if (eds[x].count(y)) eds[x][y] = min(eds[x][y], S);
        else eds[x][y] = S;
        if (eds[y].count(x)) eds[y][x] = min(eds[y][x], S);
        else eds[y][x] = S;
    }
    priority_queue<pair<LL, LL> > pq;
    for (auto p: eds[0])
        pq.push(make_pair(-p.second, p.first));
    done[0] = 1;
    int tot = 1;
    LL ans = 0;
    while (tot != n) {
        pair<LL, LL> best = pq.top();
        pq.pop();
        LL loc = best.second;
        LL wt = -best.first;
        if (done[loc]) continue;
        done[loc] = 1;
        tot++;
        ans += wt;
        for (auto p: eds[loc])
            if (!done[p.first])
                pq.push(make_pair(-p.second, p.first));
    }
    printf("%lld\n", ans);
    return 0;
}