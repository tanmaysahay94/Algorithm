#include<stdio.h>
#include<stdlib.h>
typedef struct huffData
{
	char a;
	int count;

}huffData;
typedef struct huffNode
{
	char a;
	int fr;
	struct huffNode *left,*right,*associatedTree;
}huffNode;
int cmp(const void *a,const void *b)
{
	if((*(huffData *)a).count==(*(huffData *)b).count)
		return (*(huffData *)a).a-(*(huffData *)b).a;
	return (*(huffData *)a).count-(*(huffData *)b).count;
}
int main()
{
	int breakingPoint,i,j,k,l,arrSize,insertionPoint,distinct=0,textSize=0;
	char input,text[1000000];
	huffData hd[128];
	for(i=0;i<128;i++)
	{
		hd[i].a=i;
		hd[i].count=0;
	}
	while(~(scanf("%c",&input)))
	{
		text[textSize++]=input;
		distinct+=!hd[input].count;
		hd[input].count++;
	}
	breakingPoint=distinct;
	text[textSize]='\0';
	printf("%s",text);
	huffData hArray[distinct];
	distinct=0;
	for(i=0;i<128;i++)
		if(hd[i].count)
		{
			hArray[distinct].a=hd[i].a;
			hArray[distinct].count=hd[i].count;
			distinct++;
			if(distinct==breakingPoint)
				break;
		}
	qsort(hArray,distinct,sizeof(huffData),cmp);
	arrSize=distinct;
	huffNode *root[distinct];
	for(i=0;i<distinct;i++)
	{
		root[i]->a=hArray[i].a;
		root[i]->fr=hArray[i].count;
		root[i]->left=root[i]->right=root[i]->associatedTree=NULL;
	}
	while(distinct>1)
	{
		i=j=0;
		while(i+1<distinct)
		{
			huffNode *temp=(huffNode *)malloc(sizeof(huffNode));
			temp->fr=root[i].fr+root[i+1].fr;
			temp->left=root[i];
			temp->right=root[i+1];
			for(k=i+2;k<distinct;k++)
			{
				root[k-2]->a=root[k]->a;
				root[k-2]->fr=root[k]->fr;
				root[k-2]->left=root[k-2]->right=root[k-2]->associatedTree=root[k]->left;
			}
			i+=2;
		}
	}
	return 0;
}
