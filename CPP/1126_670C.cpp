#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<int, int> cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int lang;
        scanf("%d", &lang);
        cnt[lang]++;
    }
    int b1 = 0, b2 = 0;
    int m, idx = 0;
    scanf("%d", &m);
    vector<pair<int, int> > movies(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &movies[i].first);
    for (int i = 0; i < m; i++)
        scanf("%d", &movies[i].second);
    for (int i = 0; i < m; i++)
    {
        if (cnt[movies[i].first] > b1)
        {
            b1 = cnt[movies[i].first];
            b2 = cnt[movies[i].second];
            idx = i;
        }
        else if (cnt[movies[i].first] == b1 and cnt[movies[i].second] > b2)
        {
            b2 = cnt[movies[i].second];
            idx = i;
        }
    }
    printf("%d\n", idx + 1);
}
