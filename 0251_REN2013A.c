#include<math.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int t,maxA,maxB,baseA,baseB,sum,i,lA,lB;
	char a[100],b[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		maxA=maxB=sum=0;
		for(i=0;a[i];i++)
			maxA=maxA>a[i]-'0'?maxA:a[i]-'0';
		baseA=maxA+1;
		for(i=0;b[i];i++)
			maxB=maxB>b[i]-'0'?maxB:b[i]-'0';
		baseB=maxB+1;
		lA=lB=0;
		for(i=strlen(a)-1;i>=0;i--,lA++)
			sum+=(a[i]-'0')*pow(baseA,lA);
		for(i=strlen(b)-1;i>=0;i--,lB++)
			sum+=(b[i]-'0')*pow(baseB,lB);
		printf("%d\n",sum);
	}
	return 0;
}
