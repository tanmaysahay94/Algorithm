#include<stdio.h>
inline int read()
{
	int n=0;
	char c;
	while((c=getchar_unlocked())<'0');
	n+=c-'0';
	while((c=getchar_unlocked())>='0')
		n=(n<<3)+(n<<1)+c-'0';
	return n;
}
int main()
{
	int t,n,i,j,s,found,oI,oJ;
	t=read();
	while(t--)
	{
		found=0;
		n=read();
		int a[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=read();
		s=read();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s==a[i][j])
				{
					oI=i+1;
					oJ=j+1;
					found=1;
					break;
				}
			}
			if(found)
				break;
		}
		if(found)
			printf("found\n(%d, %d)\n",oI,oJ);
		else
			printf("not found\n");
	}
	return 0;
}
