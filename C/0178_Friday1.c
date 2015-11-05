#include<stdio.h>
typedef struct map
{
	char letter;
	int frequency;
}map;
int cmp(const void *a,const void *b)
{
	if((*(map*)a).frequency==(*(map*)b).frequency)
		return (*(map*)a).letter-(*(map*)b).letter;
	return (*(map*)a).frequency-(*(map*)b).frequency;
}
int main()
{
	int t,i,n;
	char d,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%c",&n,&d);
		map l[26];
		for(i=0;i<26;i++)
		{
			l[i].frequency=0;
			l[i].letter=i+'a';
		}
		if(n)
		{
			while(n--)
			{
				scanf("%c%c",&c,&d);
				l[c-'a'].frequency++;
			}
			qsort(l,26,sizeof(map),cmp);
			printf("%c",l[25].letter);
		}
		printf("\n");
	}
	return 0;
}
