#include<stdio.h>
int main()
{
	int t,n;
	char out[6][20]={"0.45","0.945","1.4445","1.94445","2.444445","2.944445"};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n>6)
		{
			if(n&1)
				printf("%d.444444\n",n/2);
			else
				printf("%d.944444\n",n/2-1);
		}
		else
			printf("%s\n",out[n-1]);
	}
	return 0;
}
