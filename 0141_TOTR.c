#include<stdio.h>
int main()
{
	int t,i;
	char a[127],s[100],c,dump;
	scanf("%d",&t);
	scanf("%c",&dump);
	for(i=0;i<26;i++)
	{
		scanf("%c",&c);
		a[i+'a']=c;
		a[i+'A']=c-32;
	}
	while(t--)
	{
		scanf("%s",s);
		for(i=0;s[i];i++)
		{
			if(s[i]=='!'||s[i]=='.'||s[i]==','||s[i]=='?')
				printf("%c",s[i]);
			else if(s[i]=='_')
				printf(" ");
			else
				printf("%c",a[s[i]]);
		}
		printf("\n");
	}
	return 0;
}
