#include<stdio.h>
#include<string.h>
#define m 10000009
int main()
{
	int t,i,lena,j,num;
	char a[1000001];
	scanf("%d",&t);
	while(t--)
	{
		num=1;
		scanf("%s",a);
		i=0;
		j=strlen(a)-1;
		while(i<=j)
		{
			if(a[i]==a[j])
			{
				if(a[i]=='?')
					num=(num*26)%10000009;
			}
			else
			{
				if(a[i]!='?'&&a[j]!='?')
					break;
			}
			i++;
			j--;
		}
		if(i>j)
			printf("%d\n",num);
		else
			printf("0\n");
	}
	return 0;
}
