#include<stdio.h>
int main()
{
	int i,T,linelength,lineNo;
	char c,rhyme[1000],maxrhyme,check[1000][2],line[1000];
	scanf("%d",&T);
	while(T--)
	{   
		lineNo=linelength=0;
		maxrhyme='A';
		c=getchar();
		while(c=getchar())
		{
			if(c!='\n' && c!='#')
				line[linelength++]=c;
			else
			{   	
				check[lineNo][0]=line[linelength-2];
				check[lineNo][1]=line[linelength-1];    
				for(i=0;i<lineNo;i++)
				{
					if(check[lineNo][0]==check[i][0]&&check[lineNo][1]==check[i][1])
					{
						rhyme[lineNo]=rhyme[i];
						break;
					}
				}
				if(i==lineNo)
					rhyme[lineNo]=maxrhyme++;	
				if(c=='\n')
				{
					lineNo++;
					linelength=0;
				}
				if(c=='#')
				{
					lineNo++;
					break;
				}
			}
		}
		for(i=0;i<lineNo;i++)
			printf("%c",rhyme[i]);
		printf("\n");
	}   
	return 0;
}
