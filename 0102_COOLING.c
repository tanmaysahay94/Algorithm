#include<stdio.h>
int cmp(void const *a,void const *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,i,j,cool;
	scanf("%d",&t);
	while(t--)
	{
		cool=0;
		scanf("%d",&n);
		int pie[n],plate[n];
		for(i=0;i<n;i++)
			scanf("%d",pie+i);
		for(i=0;i<n;i++)
			scanf("%d",plate+i);
		qsort(pie,n,sizeof(int),cmp);
		qsort(plate,n,sizeof(int),cmp);
		j=0;
		for(i=0;i<n;i++)
		{
			if(j>=n)
				break;
			while(pie[i]>plate[j])
			{
				j++;
				if(j>=n)
					break;
			}
			if(j>=n)
				break;
			else
			{
				cool++;
				j++;
			}
		}
		printf("%d\n",cool);
	}
	return 0;
} 
