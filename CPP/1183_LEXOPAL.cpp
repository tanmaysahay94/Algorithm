
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

const int maxn = 12349;
char S[maxn];

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        scanf("%s", S);
        int len = strlen(S);
        bool possible = true;
        for (int i = 0, j = len - 1; i <= j and possible; i++, j--)
        {
            if (S[i] == S[j] and S[i] == '.')
                S[i] = S[j] = 'a';
            else
            {
                if (S[i] == '.') S[i] = S[j];
                else if (S[j] == '.') S[j] = S[i];
                else if (S[i] != S[j]) possible = false;
            }
        }
        printf("%s\n", possible ? S : "-1");
    }
    return 0;
}
