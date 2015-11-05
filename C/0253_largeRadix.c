#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct num
{
	char original[51],pad[51];
	struct num *link;
}num;
int main()
{
	int t,n,k,i,j,len,dig;
	num *temp,*ansHead,*ansTail,*bucketHead[10],*bucketTail[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
			bucketHead[i]=bucketTail[i]=NULL;
		ansHead=ansTail=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			temp=(num*)malloc(sizeof(num));
			scanf("%s",temp->original);
			len=strlen(temp->original);
			for(j=50-len;j>=0;j--)
				temp->pad[j]='0';
			for(j=51-len;j<51;j++)
				temp->pad[j]=temp->original[j+len-51];
			temp->pad[j]='\0';
			temp->link=NULL;
			if(ansHead==NULL)
				ansHead=ansTail=temp;
			else
			{
				ansTail->link=temp;
				ansTail=ansTail->link;
			}
		}							//linked list with numbers ready
		scanf("%d",&k);
		for(i=0;i<k;i++)					//(k+1) passes
		{
			while(ansHead!=NULL)
			{
				dig=ansHead->pad[50-i]-'0';		//bucket to be placed in
				temp=ansHead;
				ansHead=ansHead->link;			//linked list emptied into respective buckets
				if(bucketHead[dig]==NULL)
					bucketHead[dig]=bucketTail[dig]=temp;
				else
				{
					bucketTail[dig]->link=temp;
					bucketTail[dig]=bucketTail[dig]->link;
				}
				temp->link=NULL;
			}
			for(j=0;j<10;j++)
			{
				while(bucketHead[j]!=NULL)
				{
					temp=bucketHead[j];
					bucketHead[j]=bucketHead[j]->link;
					if(ansHead==NULL)
						ansHead=ansTail=temp;
					else
					{
						ansTail->link=temp;
						ansTail=ansTail->link;
					}
					temp->link=NULL;
				}					//j-th bucket emptied
			}						//all 10 buckets emptied
		}							//all passes completed
		while(ansHead->link!=NULL)
		{
			printf("%s ",ansHead->original);
			ansHead=ansHead->link;
		}
		printf("%s\n",ansHead->original);
	}	
	return 0;
}
