#include<stdio.h>
#include<math.h>
int main()
{
	char n[17],c;
	int i,l,flag=1,sum,len=0,done=0;
	double sum1,sum2;
	while((c=getchar())!=EOF)
	{
		if(c>='0' && c<='9')
		{
			n[len++]=c;
			done=0;
		}
		else if(done==0)
		{
			done=1;
			l=len/2;
			for(i=0;i<l;i++)
			{
				if(n[i]!=n[len-i-1])
				{
					flag=0;
					break;
				}
			}
			if(!flag)
				printf("NO\n");
			else
			{
				sum1=sum2=0.0;
				sum=0;
				printf("YES\n");
				if(len%2)
				{
					for(i=0;i<len;i++)
						sum+=(n[i]-'0');
					printf("%d\n",sum);
				}
				else
				{
					for(i=0;i<l;i++)
					{
						sum1=sum1+((double)(n[i]-'0')*pow(10,l-i-1));
						sum2=sum2+((double)(n[i+l]-'0')*pow(10,l-i-1));
					}
					if(!sum2)
						printf("0.00\n");
					else
						printf("%.2f\n",sum1/sum2);
				}
			}
			len=0;
			flag=1;
		}
	}
	return 0;
}
