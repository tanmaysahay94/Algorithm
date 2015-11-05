#include<stdio.h>
int main()
{
	int N,k,num,c;
	scanf("%d",&N);
	for(;N>0;N--)
	{
		c=0;
		scanf("%d",&num);
		while(num!=0)
		{
			k=num%10;
			if(k==3)
				c++;
			num/=10;
		}
		printf("%d\n",c);
	}
	return 0;
}
