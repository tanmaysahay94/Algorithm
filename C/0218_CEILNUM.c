#include<stdio.h>
int main()
{
	char a[1000],num[101];
	int n,i,c=0,j,b[10];
	gets(num);
	n=atoi(num);
	while(n--)
	{
		for(i=0;i<10;i++)
			b[i]=0;
		gets(a);
		for(i=0;a[i];i++);
		for(j=i-1;a[j]!=' ';j--)
			b[a[j]-'0']++;
		if(b[8]>=b[5] && b[5]>=b[3])
			if(!b[0]&&!b[1]&&!b[2]&&!b[4]&&!b[6]&&!b[7]&&!b[9])
				c++;
	}
	printf("%d\n",c);
	return 0;
} 
