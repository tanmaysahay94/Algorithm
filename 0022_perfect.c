#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	unsigned long long int n,i,s_fact,n_sqrt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%llu",&n);
		s_fact=0;
		n_sqrt=sqrt(n);
		for(i=1;i<=n_sqrt;i++)
			if(n%i==0)
				if(i!=(n/i))
					s_fact+=(i+(n/i));
				else
					s_fact+=i;
		s_fact-=n;
		printf("%llu\n",s_fact);
		if(s_fact==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
