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
#define f first
#define s second

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int a[5], t;
        if(n==0)
        {
            printf("YES\n");
            printf("1\n1\n3\n3\n");
        }
        else
        {
            scanf("%d", &a[0]);
            if(n==1)
            {
                printf("YES\n");
                printf("%d\n%d\n%d\n", a[0], a[0]*3, a[0]*3);
            }
            else if(n==2)
            {
                scanf("%d", &a[1]);
                sort(a, a+2);
                if(a[0]*3<a[1])
                    printf("NO\n");
                else
                {
                    printf("YES\n");
                    printf("%d\n%d\n", a[0]*4-a[1], a[0]*3);
                }
            }
            else if(n==3)
            {
                scanf("%d%d", &a[1], &a[2]);
                sort(a, a+3);
                if(a[2]==3*a[0])
                {
                    printf("YES\n");
                    printf("%d\n", a[0]*4-a[1]);
                }
                else if(a[2]<3*a[0]&&a[2]==a[0]*4-a[1])
                {
                    printf("YES\n");
                    printf("%d\n", 3*a[0]);
                }
                else if(a[2]%3==0&&a[2]/3*4-a[0]==a[1])
                {
                    printf("YES\n");
                    printf("%d\n", a[2]/3);
                }
                else
                    printf("NO\n");
            }
            else if(n==4)
            {
                scanf("%d%d%d", &a[1], &a[2], &a[3]);
                sort(a,a+4);
                if(a[3]!=3*a[0]||a[2]!=a[0]*4-a[1])
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
    }
    return 0;
}
