#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,l;
	char s[2100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s)-4;
		for(i=l;i>=0;i--)
			if((s[i]=='C'||s[i]=='?')&&(s[i+1]=='H'||s[i+1]=='?')&&(s[i+2]=='E'||s[i+2]=='?')&&(s[i+3]=='F'||s[i+3]=='?'))
			{
				s[i]='C';
				s[i+1]='H';
				s[i+2]='E';
				s[i+3]='F';
			}
		for(i=0;s[i];i++)
			if(s[i]=='?')
				s[i]='A';
		printf("%s\n",s);
	}
	return 0;
} 
