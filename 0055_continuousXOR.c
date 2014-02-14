#include<stdio.h>
int main()
{
	int T,input[10000],count,current_test_value,maximal,i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&count);
		for(i=0;i<count;i++)
			scanf("%d",&input[i]);
		maximal=0;
		for(i=0;i<count;i++)		    		//choosing starting point
		{
/*			for(j=i;j<count;j++)	    		//choosing ending point
			{
				current_test_value=0;
				for(k=i;k<=j;k++)	        	//traversing from start to end
					current_test_value^=input[k];
				if(current_test_value>maximal)
					maximal=current_test_value;
			}*/
			maximal|=input[i];
		}
		printf("%d\n",maximal);
	}
	return 0;
}
