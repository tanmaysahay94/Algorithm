#include<stdio.h>
int my_strlen(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}
int main()
{
	int T,i,j,lens,lenp,flag[15000]={0},check;
	scanf("%d",&T);
	char s[15000],p[1500];
	while(T--)
	{
		for(i=0;i<15000;i++)
			flag[i]=0;
		scanf("%s%s",s,p);
		lens=my_strlen(s);
		lenp=my_strlen(p);
		for(i=0;i<lens-lenp+1;i++)
		{
			check=1;
			for(j=i;j<i+lenp;j++)
				if(!((p[j-i]==s[j])||(s[j]=='?')))
				{
					check=0;
					break;
				}
			if(check==1)
				for(j=i;j<i+lenp;j++)
					s[j]=p[j-i];
		}
		for(i=0;i<lens;i++)
			if(s[i]=='?')
				s[i]='*';
		s[i]='\0';
		printf("%s\n",s);
	}
	return 0;
}
