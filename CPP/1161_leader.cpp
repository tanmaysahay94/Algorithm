
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

int f(string& s)
{
    unordered_set<char> u;
    for (auto& ss: s)
        if (ss >= 'A' and ss <= 'Z')
            u.insert(ss);
    return (int) u.size();
}

bool cmp(const pair<int, string> &l, const pair<int, string> &r)
{
    if (l.first == r.first) return l.second < r.second;
    return l.first > r.first;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N;
        scanf("%d", &N);
        getchar();
        vector<pair<int, string> > V;
        for (int i = 0; i < N; i++)
        {
            string str;
            char c;
            while ((c = getchar()) != '\n') str.push_back(c);
            V.push_back(make_pair(f(str), str));
        }
        sort(V.begin(), V.end(), cmp);
        printf("Case #%d: %s\n", T, V[0].second.c_str());
    }
    return 0;
}
