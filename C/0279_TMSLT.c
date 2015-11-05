#include<stdio.h>
#define m 1000000
int main()
{
    long long int t,n,a,b,c,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
        long long int i,array[m],new=d,sum=0,current=0;
        for(i=0;i<m;i++)
            array[i]=0;
        array[d]++;
        for(i=1;i<n;i++)
        {
            new=(a*new*new+b*new+c)%m;
            array[new]++;
        }
        for(i=0;i<m;i++)
        {
            if(!(current%2))
                sum+=(array[i]%2)*i;
            else
                sum-=(array[i]%2)*i;
            current+=array[i];
        }
        printf("%lld\n",sum>0?sum:-sum);
    }
	return 0;
}
