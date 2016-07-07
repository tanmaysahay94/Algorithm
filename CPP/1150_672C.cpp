#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<double, double> location;

vector<location> L;

inline void input(location& l){scanf("%lf%lf", &((&l)->x), &((&l)->y));}

inline double dist(location& l1, location& l2)
{
        double xdiff = l1.x - l2.x;
        xdiff *= xdiff;
        double ydiff = l1.y - l2.y;
        ydiff *= ydiff;
        return sqrt(xdiff + ydiff);
}

vector<double> gen(location& p, location& b)
{
        vector<double> ret;
        for (auto& l: L)
                ret.push_back(-dist(b, l) + dist(l, p));
        return ret;
}

double calc(double& val, vector<double>& D)
{
        double ret = LLONG_MAX;
        for (auto &d: D)
                ret = min(ret, val + d);
        return ret;
}

double both(vector<double>& A, vector<double>& B, double sum)
{
        double mn1 = LLONG_MAX;
        int idx1 = -1;
        for (int i = 0; i < (int) A.size(); i++)
                if (A[i] < mn1)
                        mn1 = A[i], idx1 = i;
        double mn2 = LLONG_MAX;
        int idx2 = -1;
        for (int i = 0; i < (int) B.size(); i++)
                if (B[i] < mn2)
                        mn2 = B[i], idx2 = i;
        if (idx1 == idx2)
        {
                mn2 = LLONG_MAX;
                idx2 = -1;
                for (int i = 0; i < (int) B.size(); i++)
                        if (i != idx1)
                                if (B[i] < mn2)
                                        mn2 = B[i], idx2 = i;
        }
        return sum + mn1 + mn2;
}

int main()
{
        location adil, bera, bin;
        input(adil);
        input(bera);
        input(bin);
        double sum = 0;
        int n;
        scanf("%d", &n);
        L = vector<location> (n);
        for (auto &l: L)
        {
                input(l);
                sum += 2 * dist(l, bin);
        }
        vector<double> A = gen(adil, bin);
        vector<double> B = gen(bera, bin);
        double v1 = calc(sum, A);
        double v2 = calc(sum, B);
        double v3 = both(A, B, sum);
        double v4 = both(B, A, sum);
        printf("%.9lf\n", min(min(v1, v2), min(v3, v4)));
        return 0;
}
