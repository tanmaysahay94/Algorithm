#include<stdio.h>
int main()
{
	int t,n,i,k,loc,locswap,swaplim,swapvar,flag,temp,templen;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		loc=-1;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",a+i);
			if(i)
				if(*(a+i)>*(a+i-1))
					loc=i-1;
		}
		if(loc==-1)
			flag=1;
		if(n==1)
			printf("%d\n",*a);
		else
		{
			if(flag)
				for(i=0;i<n;i++)
				{
					if(i!=n-1)
						printf("%d ",*(a+i));
					else
						printf("%d\n",*(a+i));
				}
			else
			{
				for(i=n-1;i>=loc+1;i--)
					if(*(a+i)>*(a+loc))
					{
						locswap=i;
						break;
					}
				temp=a[loc];
				a[loc]=a[locswap];
				a[locswap]=temp;
				templen=n-loc-1;
				int b[templen];
				for(i=0;i<templen;i++)
					*(b+templen-i-1)=*(a+loc+i+1);
				for(i=0;i<templen;i++)
					*(a+loc+i+1)=*(b+i);
				for(i=0;i<n;i++)
				{
					if(i!=n-1)
						printf("%d ",*(a+i));
					else
						printf("%d\n",*(a+i));
				}
			}
		}
	}
	return 0;
}
