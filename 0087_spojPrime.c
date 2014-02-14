#include<stdio.h>
#include<math.h>
int main()
{
	long long int memorize[1000005]={0};
	long long int lowlim,highlim,N,j,c,num;
	float s;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%lld%lld",&lowlim,&highlim);
		for(num=lowlim;num<=highlim;num++)
		{
			if(memorize[num])
				printf("%lld\n",num);
			else
			{
				s=sqrt(num);
				if(num==1||num==0)
					continue;
				else if(num==2||num==3)
				{
					memorize[num]=num;
					printf("%lld\n",num);
				}
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
					{
						if(num<1000000)
							memorize[num]=num;
						printf("%lld\n",num);
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		printf("\n");
	}
	return 0;
}
