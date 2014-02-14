#include<stdio.h>
int main()
{
	int T,r,c,p,i,j,count,sz,printlimit,top,bottom,left,right,dir;
	char s[1000],e[100][100],output[1000];
	scanf("%d",&T);
	while(T--)
	{
		top=left=dir=0;
		count=0;
		scanf("%s%d%d%d",s,&r,&c,&p);
		sz=r*c;
		bottom=r-1;
		right=c-1;
		printlimit=sz-p;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(count<sz)
					e[i][j]=s[count++];
		count=0;
		while(top<=bottom&&left<=right)
		{
			if(dir==0)
			{
				for(i=left;i<=right;i++)
					if(count<printlimit)
						output[count++]=e[top][i];
					else 
						break;
				top++;
			}
			else if(dir==1)
			{
				for(i=top;i<=bottom;i++)
					if(count<printlimit)
						output[count++]=e[i][right];
					else 
						break;
				right--;
			}
			else if(dir==2)
			{
				for(i=right;i>=left;i--)
					if(count<printlimit)
						output[count++]=e[bottom][i];
					else 
						break;
				bottom--;
			}
			else if(dir==3)
			{
				for(i=bottom;i>=top;i--)
					if(count<printlimit)
						output[count++]=e[i][left];
					else 
						break;
				left++;
			}
			dir=(dir+1)%4;
		}
		output[count]='\0';
		printf("%s\n",output);
	}
	return 0;
}
