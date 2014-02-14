#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==0)
			printf("1\n");
		else if(n==1)
			printf("0\n");
		else if(n==2)
			printf("1\n");
		else if(n==3)
			printf("2\n");
		else if(n==4)
			printf("9\n");
		else if(n==5)
			printf("44\n");
		else if(n==6)
			printf("265\n");
		else if(n==7)
			printf("1854\n");
		else if(n==8)
			printf("14833\n");
		else if(n==9)
			printf("133496\n");
		else if(n==10)
			printf("1334961\n");
		else if(n==11)
			printf("14684570\n");
		else if(n==12)
			printf("176214841\n");
		else if(n==13)
			printf("2290792932\n");
		else if(n==14)
			printf("32071101049\n");
		else if(n==15)
			printf("481066515734\n");
		else if(n==16)
			printf("7697064251745\n");
		else if(n==17)
			printf("130850092279664\n");
		else if(n==18)
			printf("2355301661033953\n");
		else if(n==19)
			printf("44750731559645106\n");
		else if(n==20)
			printf("895014631192902121\n");
	}
	return 0;
}
