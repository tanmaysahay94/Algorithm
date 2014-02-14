#include<stdio.h>
int ispalin(int i)
{
	int temp,reverse;
	temp=i;
	reverse=0;
	while(temp!=0)
	{
		reverse=reverse*10;
		reverse=reverse+temp%10;
		temp=temp/10;
	}
	if(i==reverse)
		return 1;
	else return 0;
}
int palin(int i)
{
	int temp,reverse;
	reverse=0;
	temp=i;
	while(temp!=0)
	{
		reverse=reverse*10;
		reverse=reverse+temp%10;
		temp=temp/10;
	}
	return reverse;
}
int main()
{
	int i,t,n,ans,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		i=1;
		while(i>0)
		{
			ans=n+palin(n);
			n=ans;
			i++;
			if(ispalin(ans)==1)
				break;
		}
		printf("%d %d\n",(i-1),ans);
	}
	return 0;
}
