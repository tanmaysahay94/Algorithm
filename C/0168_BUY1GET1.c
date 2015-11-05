#include<string.h>
#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(char*)a-*(char*)b;
}
int main()
{
	int cost,t,k,i;
	char jewel[250];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",jewel);
		qsort(jewel,(k=strlen(jewel)),sizeof(char),cmp);
		jewel[k]='1';
		jewel[k+1]='\0';			//padding to prevent segFault
		cost=i=0;
		while(i<k)
		{
			cost++;
			if(jewel[i]==jewel[i+1])
				i+=2;
			else
				i++;
		}
		printf("%d\n",cost);
	}
	return 0;
}
