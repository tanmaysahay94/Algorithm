#include<stdio.h>
int main()
{
	unsigned long long int i,t,no_of_elements,product,element,no_of_queries,query,flag,flag_mult_zero;
	scanf("%llu",&t);
	while(t--)
	{
		flag=0;
		flag_mult_zero=0;
		product=1;
		scanf("%llu",&no_of_elements);
		unsigned long long int array[no_of_elements];
		for(i=0;i<no_of_elements;i++)
		{
			scanf("%llu",&array[i]);
			if(array[i])
				product*=array[i];
			else
			{
				if(!flag)
					flag=1;
				else
					flag_mult_zero=1;
			}
		}
		scanf("%llu",&no_of_queries);
		while(no_of_queries--)
		{
			scanf("%llu",&query);
			if(flag)
			{
				if(flag_mult_zero)
					printf("0 ");
				else
				{
					if(array[query])
						printf("0 ");
					else
						printf("%llu ",product);
				}
			}
			else
				printf("%llu ",product/array[query]);
		}
		printf("\n");
	}
	return 0;
}
