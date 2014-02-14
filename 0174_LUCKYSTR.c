#include<stdio.h>
#include<string.h>
typedef struct lString
{
	char word[55];
	int len;
}lString;
int cmp(const void *a,const void *b)
{
	if((*(lString*)a).len==(*(lString*)b).len)
		return strcmp((*(lString*)a).word,(*(lString*)b).word);
	return (*(lString*)a).len-(*(lString*)b).len;
}
int substringSearch(char big[],char small[],int lenBig,int lenSmall)
{
	int start,j,flag,reqLen=lenBig-lenSmall;
	for(start=0;start<=reqLen;start++)
	{
		flag=1;
		for(j=start;j<start+lenSmall;j++)
			if(big[j]!=small[j-start])
			{
				flag=0;
				break;
			}
		if(flag)
			break;
	}
	return flag;
}
int main()
{
	int f,i,n,k,count,check;
	scanf("%d%d",&n,&count);
	lString ls[n];
	char d,w[55];
	scanf("%c",&d);
	for(i=0;i<n;i++)
	{
		scanf("%s",ls[i].word);
		ls[i].len=strlen(ls[i].word);
	}
	qsort(ls,n,sizeof(lString),cmp);
	while(count--)
	{
		f=0;
		scanf("%s",w);
		if((k=strlen(w))>=47)
			f=1;
		else
		{
			check=n-1;
			while(ls[check].len>k)
			{
				check--;
				if(check<0)
					break;
			}
			if(check>=0)
			{
				for(i=check;i>=0;i--)
					if(substringSearch(w,ls[i].word,k,ls[i].len))
					{
						f=1;
						break;
					}
			}
		}
		if(f)
			printf("Good\n");
		else
			printf("Bad\n");
	}
	return 0;
}
