#include<stdio.h>
int main()
{
	char r[1200],s[1200],d;
	int a[26],b[26],t,i,ans;
	scanf("%d%c",&t,&d);
	while(t--)
	{
		ans=1;
		scanf("%s%s",r,s);
		for(i=0;i<26;i++)
			a[i]=b[i]=0;
		for(i=0;r[i];i++)
			a[r[i]-'a']++;
		for(i=0;s[i];i++)
			b[s[i]-'a']++;
		for(i=0;i<26;i++)
		{
			if(a[i]==b[i])
				continue;
			if((!a[i]&&b[i])||(a[i]&&!b[i]))
			{
				ans=42;
				break;
			}
			else
				ans=0;
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
