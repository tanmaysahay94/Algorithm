#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool invalid(LL a, LL b, LL c)
{
    return a >= b + c or b >= a + c or c >= a + b;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<LL> l(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &l[i]);
    vector<LL> best(3), temp(3);
    LL bestSum = 0;
    bool found = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (i != j and i != k and j != k)
                {
                    LL tempSum = l[i] + l[j] + l[k];
                    if (invalid(l[i], l[j], l[k]))
                        continue;
                    if (tempSum > bestSum)
                    {
                        bestSum = tempSum;
                        best[0] = l[i];
                        best[1] = l[j];
                        best[2] = l[k];
                        sort(best.begin(), best.end());
                        found = true;
                    }
                    else if (tempSum == bestSum)
                    {
                        temp[0] = l[i];
                        temp[1] = l[j];
                        temp[2] = l[k];
                        sort(temp.begin(), temp.end());
                        if (temp[2] > best[2])
                            best = temp;
                        else if (temp[2] == best[2] and temp[0] > best[0])
                            best = temp;
                    }
                }
    if (not found)
        printf("-1");
    else
        for (auto b: best)
            printf("%lld ", b);
    printf("\n");
    return 0;
}
