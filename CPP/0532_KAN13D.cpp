#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

const LL mod = 1e9 + 7;
 
LL a[101][101], p[101][101];
LL m;
 
void mul(LL m1[101][101], LL m2[101][101])
{
    LL tmp1[101][101], tmp2[101][101];
    for(LL i = 0; i < m; i++)
        for(LL j = 0; j < m; j++)
		{
            tmp1[i][j] = m1[i][j];
            tmp2[i][j] = m2[i][j];
            p[i][j] = 0;
        }
    for(LL i = 0; i < m; i++)
        for(LL j = 0; j < m; j++)
            for(LL k = 0; k < m; k++)
			{
                p[i][j] += (tmp1[i][k] * tmp2[k][j]);
                p[i][j] %= mod;
            }
}
 
void power(LL n)
{
    if(n==0 or n==1)
        return;
    power(n>>1);
    mul(p, p);
    if(n&1)
        mul(p, a);
}
 
int main()
{
    LL t, n;
    SLL(t);
    while(t--)
	{
		SLL(m); SLL(n);
        LL s[m+1];
        for(LL i = 0; i < m; i++)
		{
			SLL(s[i]);
            s[i] += mod;
        }
        for(LL i = 0; i < m; i++)
            SLL(a[0][m-1-i]);
        for(LL i = 1; i < m; i++)
            for(LL j = 0; j < m; j++)
                if(i==(j+1))
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
        for(LL i = 0; i < m; i++)
            for(LL j = 0; j < m; j++)
                p[i][j] = a[i][j];
        if(m <= n) 
		{
            power(n-m+1);
            LL ans = 0;
            for(LL i = 0; i < m; i++)
			{
                ans += (p[0][i]*s[m-1-i]);
                ans %= mod;
            }
			printf("%lld\n", ans);
        }
        else
            printf("%lld\n", s[n]%mod);
    }
    return 0;
}
