#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;
char w[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        LL k;
        scanf("%s%lld", w, &k);
        unordered_map<char, LL> u_map;
        for (int i = 0; w[i]; i++)
            u_map[w[i]]++;
        if (u_map.size() == 1)
        {
            printf("0\n");
            continue;
        }
        LL ans = LLONG_MAX;
        for (auto &c: u_map)    // consider this to be the minimum frequency character
        {
            LL tmp = 0;
            for (auto &d: u_map)
            {
                if (d.second < c.second) tmp += d.second;
                else if (d.second > c.second + k) tmp += d.second - (c.second + k);
            }
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
