
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

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int C, I;
        scanf("%d%d", &C, &I);
        vector<pair<int, int> > V;
        for (int i = 1; i <= I; i++)
        {
            int P;
            scanf("%d", &P);
            V.push_back(make_pair(P, i));
        }
        sort(V.begin(), V.end());
        int s = 0, e = I - 1;
        while (s < e)
        {
            int sum = V[s].first + V[e].first;
            if (sum == C)
                break;
            else if (sum > C)
                e--;
            else
                s++;
        }
        printf("Case #%d: %d %d\n", T, min(V[s].second, V[e].second), max(V[s].second, V[e].second));
    }
    return 0;
}
