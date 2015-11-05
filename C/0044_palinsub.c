#include<stdio.h>
int palin(char a[],int len)
{
	int k;
	for(k=0;k<len/2;k++)
		if(a[k]!=a[len-k-1])
			return 0;
	return 1;
}
int my_strlen(char a[])
{
	int i;
	for(i=0;a[i];i++);
	return i;
}
int main()
{
	char string[2000],intermediate[2000];
	int sLen,i,j,k,l,len,maxlen,flag=0;
	while(scanf("%s",string)!=EOF)
	{
		sLen=my_strlen(string);
		maxlen=0;
		for(i=0;i<sLen;i++)
		{
			flag=0;
			for(j=sLen-1;j>=i;j--)
			{
				len=1+j-i;
				if(len>=maxlen)
				{
					if(palin(&string[i],len))
					{
						if(len>maxlen)
						{
							maxlen=len;
							for(k=i;k<=j;k++)
								intermediate[k-i]=string[k];
						}
						else if(len==maxlen)
						{
							for(k=i;k<=j;k++)
							{
								if(string[k]>intermediate[k-i])
								{
									flag=1;
									break;
								}
								if(string[k]<intermediate[k-i])
								{
									for(l=i;l<=j;l++)
										intermediate[l-i]=string[l];
									flag=1;
									break;
								}
							}
						}
					}
				}
				if(flag)
					break;
			}
		}
		for(k=0;k<maxlen;k++)
			printf("%c",intermediate[k]);
		printf("\n");
		flag=0;
	}
	return 0;
}
