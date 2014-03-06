#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
int lookUpHeight,foundMyNode,foundIRNode,subTreeCount,subTreeInOrder[1000000],levelElementCount,level[1000000];
void insert(node *tree,node *leaf)
{
	if(leaf->data<tree->data)
		if(tree->left)
			insert(tree->left,leaf);
		else
			tree->left=leaf;
	else
		if(tree->right)
			insert(tree->right,leaf);
		else
			tree->right=leaf;
}
int getHeight(node *tree,int val)
{
	if(tree)
		if(val==tree->data)
			return lookUpHeight;
		else
		{
			lookUpHeight++;
			if(val<tree->data)
				getHeight(tree->left,val);
			else
				getHeight(tree->right,val);
		}
	else
		return 0;
}
void generateSubTree(node *tree)
{
	if(tree)
	{
		generateSubTree(tree->left);
		subTreeInOrder[subTreeCount++]=tree->data;
		generateSubTree(tree->right);
	}
}
void levelCreate(node *tree,int height)
{
	if(tree)
	{
		if(height==1)
			level[levelElementCount++]=tree->data;
		else
		{
			levelCreate(tree->left,height-1);
			levelCreate(tree->right,height-1);
		}
	}
}
void findAndGenerate(node *tree,int val)
{
	if(tree)
	{
		if(val<tree->data)
			findAndGenerate(tree->left,val);
		else if(val>tree->data)
			findAndGenerate(tree->right,val);
		else 
			generateSubTree(tree);
	}
}
int main()
{
	int t,n,myNode,k,i;
	scanf("%d",&t);
	while(t--)
	{
		levelElementCount=foundMyNode=foundIRNode=subTreeCount=0;
		lookUpHeight=1;
		node *bst=NULL,*temp;
		scanf("%d",&n);
		while(n--)
		{
			temp=(node *)malloc(sizeof(node));
			scanf("%d",&temp->data);
			temp->left=temp->right=NULL;
			if(bst==NULL)
				bst=temp;
			else
				insert(bst,temp);
		}
		scanf("%d%d",&myNode,&k);
		if(lookUpHeight=getHeight(bst,myNode))
		{
			levelCreate(bst,lookUpHeight);
			for(i=0;i<levelElementCount;i++)
				if(level[i]==myNode)
					break;
			if(i==levelElementCount-1)
				printf("$ $\n");
			else
			{
				printf("%d ",level[i+1]);
				findAndGenerate(bst,level[i+1]);
				if(k>subTreeCount)
					printf("$\n");
				else
					printf("%d\n",subTreeInOrder[k-1]);
			}
		}
		else
			printf("$ $\n");
	}
	return 0;
}
