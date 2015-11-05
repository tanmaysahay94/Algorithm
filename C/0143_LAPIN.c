#include<stdio.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	return *(char*)a-*(char*)b;
}
int main()
{
	int t,i,lenS,k;
	char S[1050],first[1050],last[1050];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",S);
		lenS=strlen(S);
		k=lenS/2;
		for(i=0;i<k;i++)
			first[i]=S[i];
		first[i]='\0';
		qsort(first,k,sizeof(char),cmp);
		if(lenS&1)
		{
			for(i=k+1;i<lenS;i++)
				last[i-k-1]=S[i];
			last[i-k-1]='\0';
			qsort(last,k,sizeof(char),cmp);
		}
		else
		{
			for(i=k;i<lenS;i++)
				last[i-k]=S[i];
			last[i-k]='\0';
			qsort(last,k,sizeof(char),cmp);
		}
		if(!strcmp(first,last))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
