#include <bits/stdc++.h>

using namespace std;

vector<int> diff;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        diff = vector<int> (n);
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            int time;
            scanf("%d", &time);
            diff[i] = time - prev;
            prev = time;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int req;
            scanf("%d", &req);
            ans += req <= diff[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
