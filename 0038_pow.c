#include<stdio.h>
#include<math.h>
void powset(int b[],int n)
{
	int total=pow(2,n);
	int i,j,ref,var,flag[total];
	for(i=0;i<total;i++)
		flag[i]=0;
	for(i=0;i<total;i++)
	{
		var=i;
		printf("{");
		ref=0;
		j=0;
		while(var)
		{
			flag[j++]=var%2;
			if(var%2)
				ref++;
			var/=2;
		}
		while(ref)
		{
			if(flag[j]==1)
			{
				if(ref>1)
					printf("%d, ",b[j]);
				else
					printf("%d",b[j]);
				ref--;
			}
			j--;
		}
		printf("}\n");
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	int a[num],i;
	for(i=0;i<num;i++)
		scanf("%d",&a[i]);
	powset(a,num);
	return 0;
}
