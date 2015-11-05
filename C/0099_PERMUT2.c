#include<stdio.h>
int main()
{
	int size,i,ambiguous;
	scanf("%d",&size);
	while(size)
	{
		ambiguous=1;
		int array[++size];
		array[0]=0;
		for(i=1;i<size;i++)
			scanf("%d",array+i);
		for(i=1;i<size;i++)
		{
			if(array[array[i]]!=i)
			{
				ambiguous=0;
				break;
			}
		}
		if(ambiguous)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		scanf("%d",&size);
	}
	return 0;
} 
