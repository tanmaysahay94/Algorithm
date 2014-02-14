#include<stdio.h>
#include<math.h>
int is_prime(int num)
{
	int s,c,j;
	s=sqrt(num);
	if(num==1||num==0)
		return 0;
	else if(num==2||num==3)
		return 1;
	else if((num)%6==1||(num)%6==5)
	{
		c=0;
		for(j=3;j<=s;j+=2)
		{
			if(!(num%j))
			{
				c=1;
				break;
			}
		}
		if(!c)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int main()
{
	unsigned int n,s,i,kcount,fact_prod=1;
	scanf("%u",&n);
	s=sqrt(n);
	if(n%2==0)
		printf("No\n");
	else
	{
		kcount=0;
		for(i=3;i<=s;i++)
			if(n%i==0)
				if(!((n-1)%(i-1)))
					if(is_prime(i))
					{
						kcount++;
						fact_prod*=i;
					}
		if((kcount>=3)&&(fact_prod==n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
