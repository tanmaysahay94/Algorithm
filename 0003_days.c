#include<stdio.h>
int is_leap(int a)
{
	if(a%100==0)
	{
		if(a%400==0)
			return 1;
		else
			return 0;
	}
	else if(a%4==0)
		return 1;
	else
		return 0;
}
int main()
{
	int N,dd1,mm1,yy1,dd2,mm2,yy2,i,j,t;
	unsigned long long int days;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d%d%d",&dd1,&mm1,&yy1,&dd2,&mm2,&yy2);
		mm1--;
		mm2--;
		if(yy1>yy2||(yy1==yy2&&mm1>mm2)||(yy1==yy2&&mm1==mm2&&dd1>dd2))
		{
			t=dd1;
			dd1=dd2;
			dd2=t;
			t=mm1;
			mm1=mm2;
			mm2=t;
			t=yy1;
			yy1=yy2;
			yy2=t;
		}
		days=0;
		for(i=yy1;i<=yy2;i++)              //addition of days from first year to last year
		{
			if(is_leap(i))
				month[1]=29;
			else
				month[1]=28;
			for(j=0;j<12;j++)
				days+=month[j];
		}
		if(is_leap(yy1))
			month[1]=29;
		else
			month[1]=28;
		for(i=0;i<mm1;i++)
			days-=month[i];           //removal of days of months in the beginning till before the month input
		if(is_leap(yy2))
			month[1]=29;
		else
			month[1]=28;
		for(i=11;i>=mm2;i--)
			days-=month[i];           //removal of days of months in the end including the month input
		days-=(dd1-1);                    //removal of days before the date in the month
		days+=dd2;                        //addition of days of the last month
		printf("%llu\n",days);
	}
	return 0;
}
