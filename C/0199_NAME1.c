#include<stdio.h>
int main()
{
	int t,n,i,l[26],p;
	char c,dad[500000],mom[500000],kid[500000];
	scanf("%d%c",&t,&c);
	while(t--)
	{
		p=0;
		for(i=0;i<26;i++)
			l[i]=0;
		scanf("%s%s",dad,mom);
		for(i=0;dad[i];i++)
			l[dad[i]-'a']++;
		for(i=0;mom[i];i++)
			l[mom[i]-'a']++;
		scanf("%d%c",&n,&c);
		while(n--)
		{
			scanf("%s",kid);
			for(i=0;kid[i];i++)
				l[kid[i]-'a']--;
		}
		for(i=0;i<26;i++)
			if(l[i]<0)
			{
				p=1;
				break;
			}
		if(p)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
