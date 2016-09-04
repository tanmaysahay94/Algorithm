
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

bool isLower(char c)
{
    return c >= 'a' and c <= 'z';
}

char toUpper(char c)
{
    if (not isLower(c)) return c;
    return c - 'a' + 'A';
}

bool dp[1011][1011];

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        string A, B;
        cin >> A >> B;
        for (int i = 0; i <= A.size(); i++)
            for (int j = 0; j <= B.size(); j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j <= B.size(); j++)
                if (dp[i][j])
                {
                    if (j < B.size() and toUpper(A[i]) == B[j])
                        dp[i + 1][j + 1] = 1;
                    if (isLower(A[i]))
                        dp[i + 1][j] = 1;
                }
        printf("%s", dp[A.size()][B.size()] ? "YES\n" : "NO\n");
    }
    return 0;
}
