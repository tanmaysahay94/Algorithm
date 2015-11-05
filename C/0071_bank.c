#include<stdio.h>
int arr[1000000]={0};
int returns(int n)
{
	if(n>=1000000||!arr[n])
	{
		if(n/2+n/3+n/4<n)
		{
			if(n<1000000)
				arr[n]=n;
			return n;
		}
		else
		{
			if(n<1000000)
			{
				arr[n]=returns(n/2)+returns(n/3)+returns(n/4);
				return arr[n];
			}
			else
				return(returns(n/2)+returns(n/3)+returns(n/4));
		}
	}
	else
		return arr[n];

}
int main()
{
	int investment;
	while(scanf("%d",&investment)!=EOF)
		printf("%d\n",returns(investment));
	return 0;
}
