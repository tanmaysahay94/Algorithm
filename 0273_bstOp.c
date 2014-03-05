#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
int lookUpHeight,foundMyNode,foundIRNode,subTreeCount,subTreeInOrder[1000000];
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
void findIRNode(node *tree,int val,int height)
{
	if(height==1)
	{
		if(foundMyNode==1)
		{
			generateSubTree(tree);
			printf("%d ",tree->data);
			foundIRNode=1;
		}
		if(tree->data==val)
			foundMyNode=1;
		return;
	}
	else
	{
		if(tree->left)
			findIRNode(tree->left,val,height-1);
		if(tree->right)
			findIRNode(tree->right,val,height-1);
	}
}
int main()
{
	int t,n,myNode,k,i;
	scanf("%d",&t);
	while(t--)
	{
		foundMyNode=foundIRNode=subTreeCount=0;
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
			findIRNode(bst,myNode,lookUpHeight);
			if(!foundIRNode)
				printf("$ $\n");
			else
			{
				if(k>subTreeCount)
					printf("$\n");
				else
					printf("%d\n",subTreeInOrder[k-1]);
			}
		}
		else
			printf("$ $\n");
		lookUpHeight=1;
	}
	return 0;
}
