#include<stdio.h>
int encore(int a,int num)
{
	int t;
	t=a;
	while(t)
	{
		a+=t%10;
		t/=10;
	}
	if(a!=num)
		return 0;
	return 1;
}
int main()
{
	int t,n,f,answer;
	scanf("%d",&t);
	while(t--)
	{
		f=0;
		answer=1;
		scanf("%d",&n);
		while(!encore(++answer,n)&&answer<=n);
		if(answer>n)
			printf("NONE\n");
		else
			printf("%d\n",answer);
	}
	return 0;
}
