#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,fAns,wAns,len,head;
	char e[1000100],s[1000100];
	scanf("%d",&t);
	while(t--)
	{
		head=-1;
		fAns=wAns=0;
		scanf("%s",e);
		len=strlen(e);
		for(i=0;i<len;i++)
		{
			if(e[i]=='<')
				s[++head]=e[i];
			else
			{
				if(head==-1)
					break;
				else
				{
					wAns++;
					head--;
					if(head==-1)
					{
						fAns+=wAns;
						wAns=0;
					}
				}
			}
		}
		printf("%d\n",fAns<<1);
	}
	return 0;
}
