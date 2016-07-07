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

typedef long long LL;

vector<pair<LL, LL> > points;
vector<bool> done;
LL ax, ay, bx, by, tx, ty, n;

double dist(LL x1, LL y1, LL x2, LL y2)
{
    LL sqr = (x1 - x2) * (x1 - x2);
    sqr += (y1 - y2) * (y1 - y2);
    return sqrt(sqr);
}

pair<double, int> getMin(LL x, LL y)
{
    int mnIdx = -1;
    double mnDist = LLONG_MAX;
    for (int i = 0; i < (int) points.size(); i++)
    {
        double tmpDist = dist(x, y, points[i].first, points[i].second);
        tmpDist += dist(points[i].first, points[i].second, tx, ty);
        if (tmpDist < mnDist) 
        {
            mnDist = tmpDist;
            mnIdx = i;
        }
    }
    return make_pair(mnDist, mnIdx);
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &tx, &ty, &n);
    for (int i = 0; i < n; i++)
    {
        LL x, y;
        scanf("%lld%lld", &x, &y);
        points.push_back(make_pair(x, y));
        done.push_back(false);
    }
    double ans = 0;
    pair<double, int> foo = getMin(ax, ay);
    pair<double, int> bar = getMin(bx, by);
    trace(foo.first, foo.second);
    trace(bar.first, bar.second);
    int atCentre;
    if (foo.first < bar.first)
    {
        ans += foo.first;
        done[foo.second] = 1;
        atCentre = 0;       // a
    }
    else
    {
        ans += bar.first;
        done[bar.second] = 1;
        atCentre = 1;       // b
    }
    priority_queue<pair<double, int> > pq;
    for (int i = 0; i < n; i++)
        if (not done[i])
            if (atCentre == 0)
            {
                pq.push(make_pair(-dist(points[i].first, points[i].second, tx, ty) * 2, i));
                pq.push(make_pair(-dist(points[i].first, points[i].second, bx, by) - dist(points[i].first, points[i].second, tx, ty), i || (1 << 25)));
            }
            else
            {
                pq.push(make_pair(-dist(points[i].first, points[i].second, ax, ay) - dist(points[i].first, points[i].second, tx, ty), i));
                pq.push(make_pair(-dist(points[i].first, points[i].second, tx, ty) * 2, i || (1 << 25)));
            }
    int cnt = 1;
    while (cnt < n)
    {
        pair<double, int> best = pq.top();
        pq.pop();
        int sec = best.second;
        int type = sec >> 25;
        int idx = sec ^ (type << 25);
        if (done[idx]) continue;
        ans -= best.first;
        done[idx] = 1;
        cnt++;
        if (atCentre ^ type) break;
    }
    for (int i = 0; i < n; i++)
        if (not done[i])
            ans += 2 * dist(points[i].first, points[i].second, tx, ty);
    printf("%.6lf\n", ans);
    return 0;
}
