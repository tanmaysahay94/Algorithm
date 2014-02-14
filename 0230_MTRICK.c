#include<stdio.h>
int main()
{
	unsigned long long int t,l[1500],a,b,c,i,j,n,m,mm;
	char w[1500];
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu",&n);
		for(i=0;i<n;i++)
			scanf("%llu",l+i);
		scanf("%llu%llu%llu%s",&a,&b,&c,w);
		for(i=0;w[i];i++)
		{
			if(w[i]=='A')
				for(j=i;j<n;j++)
					l[j]=((l[j]%c)+(a%c))%c;
			else if(w[i]=='M')
				for(j=i;j<n;j++)
					l[j]=((l[j]%c)*(b%c))%c;
			else if(w[i]=='R')
			{
				mm=i+n;
				m=mm/2;
				for(j=i;j<m;j++)
					l[j]=l[j]+l[mm-1-j]-(l[mm-1-j]=l[j]);
			}
		}
		for(i=0;i<n-1;i++)
			printf("%llu ",l[i]%c);
		printf("%llu\n",l[i]%c);
	}
	return 0;
}
