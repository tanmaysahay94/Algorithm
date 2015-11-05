#include<stdio.h>
#include<math.h>
int main()
{
	int N,num,j,c;
	float s;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&num);
		s=sqrt(num);
		if(num==1||num==0)
			printf("FALSE\n");
		else if(num==2||num==3)
			printf("TRUE\n");
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
				printf("TRUE\n");
			else
				printf("FALSE\n");
		}
		else
			printf("FALSE\n");
	}
	return 0;
}
