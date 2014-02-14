#include<stdio.h>
int main()
{
	int l,m,n,p,q,d1,d2;
	scanf("%d%d%d",&l,&m,&n);
	p=((d1=m-l)==1);
	q=((d2=n-m)==1);
	if(p&&q)
		printf("0\n");
	else
		if(d2>=d1)
			printf("%d\n",n-m-1);
		else
			printf("%d\n",m-l-1);
	return 0;
}
