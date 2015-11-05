#include<stdio.h>
#include<math.h>
int cmp(void const *a,void const *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,m,i,possibilities,j,sum,count,payup;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int note[n];
		for(i=0;i<n;i++)
			scanf("%d",note+i);
		possibilities=pow(2,n);
		qsort(note,n,sizeof(int),cmp);
		payup=0;
		for(i=1;i<possibilities;i++)
		{
			sum=count=0;
			j=i;
			while(j)
			{
				if(j&1)
				{
					sum+=note[count];
					if(sum>=m)
						break;//break out of while(j)
				}
				j>>=1;
				count++;
			}//end of while(j)
			if(sum==m)
			{
				payup=1;
				break;//break out of powerset loop
			}
		}//end of powerset loop
		if(payup)
			printf("Yes\n");
		else
			printf("No\n");
	}//end of testcases
	return 0;
} 
