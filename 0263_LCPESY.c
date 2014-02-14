#include<stdio.h>
int main()
{
	int t,i,count,min,fSmall[26],sSmall[26],fBig[26],sBig[26],fNum[10],sNum[10];
	char a[50000],b[50000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		for(i=0;i<26;i++)
			fSmall[i]=fBig[i]=sSmall[i]=sBig[i]=0;
		for(i=0;i<10;i++)
			fNum[i]=sNum[i]=0;
		for(i=0;a[i];i++)
		{
			if(a[i]>='a'&&a[i]<='z')
				fSmall[a[i]-'a']++;
			else if(a[i]>='A'&&a[i]<='Z')
				fBig[a[i]-'A']++;
			else if(a[i]>='0'&&a[i]<='9')
				fNum[a[i]-'0']++;
		}
		for(i=0;b[i];i++)
		{
			if(b[i]>='a'&&b[i]<='z')
				sSmall[b[i]-'a']++;
			else if(b[i]>='A'&&b[i]<='Z')
				sBig[b[i]-'A']++;
			else if(b[i]>='0'&&b[i]<='9')
				sNum[b[i]-'0']++;
		}
		count=0;
		for(i=0;i<26;i++)
		{
			min=fSmall[i]<=sSmall[i]?fSmall[i]:sSmall[i];
			count+=min;
			min=fBig[i]<=sBig[i]?fBig[i]:sBig[i];
			count+=min;
		}
		for(i=0;i<10;i++)
		{
			min=fNum[i]<=sNum[i]?fNum[i]:sNum[i];
			count+=min;
		}
		printf("%d\n",count);
	}
	return 0;
}
