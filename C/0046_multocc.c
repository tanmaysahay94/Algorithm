#include<stdio.h>
int my_strlen(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}
int check(char p[],char q[],int j,int limit)
{
	int k;
	for(k=0;k<limit;k++,j++)
		if(p[k]!=q[j])
			return 0;
	return 1;
}
int main()
{
	int T,i,j,lena,lenrem,oCount;
	char a[696969],rem[696968],output[696969];
	scanf("%d",&T);
	while(T--)
	{
		oCount=0;
		int flag[696969]={0};
		scanf("%s%s",a,rem);
		lena=my_strlen(a);
		lenrem=my_strlen(rem);
		for(i=0;i<1+lena-lenrem;i++)
			if(*rem==*(a+i))
				if(check(rem,a,i,lenrem))
					for(j=i;j<i+lenrem;j++)
						flag[j]=1;
		for(i=0;i<lena;i++)
			if(flag[i]==0)
				output[oCount++]=a[i];
		output[oCount]='\0';
		printf("%s\n",output);
	}
	return 0;
}
