#include<stdio.h>
int in(int p,int q)
{
	int i,r=0;
	for(i=0;i<q;i++)
	{
		r<<=1;
		r+=(p&1);
		p>>=1;
	}
	return r;
}
int main()
{
	int t,b,i;
	char m[65537],o[65537];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&b,m);
		for(i=0;m[i];i++)
			o[in(i,b)]=m[i];
		o[i]='\0';
		printf("%s\n",o);
	}
	return 0;
}
