#include<stdio.h>
typedef struct data
{
	int number;
	int address;
}data;
int cmp(const void *a,const void *b)
{
	if ((*(data *)a).number == (*(data *)b).number)
		return (*(data *)a).address -(*(data *)b).address;
	return (*(data *)a).number-(*(data *)b).number;
}
int main()
{
	int n,k,i,j,aDog,bDog,found=0;
	scanf("%d%d",&n,&k);
	data d[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i].number);
		d[i].address=i;
	}
	qsort(d,n,sizeof(data),cmp);
	i=0;
	j=n-1;
	while(i<j)
	{
		if(d[i].number+d[j].number==k&&d[i].number!=d[j].number)
		{
			found=1;
			break;
		}
		else if(d[i].number+d[j].number<k)
			i++;
		else
			j--;
	}
	if(!found)
		printf("-1\n");
	else
	{
		aDog=d[i].address<d[j].address?d[i].address:d[j].address;
		bDog=d[i].address>d[j].address?d[i].address:d[j].address;
		aDog++;
		bDog=n-bDog;
		printf("%d\n",aDog>bDog?aDog:bDog);
	}
	return 0;
}
