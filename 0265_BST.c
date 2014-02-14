#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *leftChild,*rightChild;
}node;
void insert(node *tree,node *leaf)
{
	if(tree->data>leaf->data)
	{
		if(tree->leftChild==NULL)
			tree->leftChild=leaf;
		else
			insert(tree->leftChild,leaf);
	}
	else
	{
		if(tree->rightChild==NULL)
			tree->rightChild=leaf;
		else
			insert(tree->rightChild,leaf);
	}
}
void search(node *tree,int val)
{
	if(tree)
	{
		if(tree->data==val)
		{
			printf("found\n");
			return;
		}
		else
		{
			if(val>tree->data)
				search(tree->rightChild,val);
			else
				search(tree->leftChild,val);
		}
	}
	else
		printf("Not found\n");
}
void inOrder(node *tree)
{
	if(tree)
	{
		inOrder(tree->leftChild);
		printf("%d\n",tree->data);
		inOrder(tree->rightChild);
	}
}
void preOrder(node *tree)
{
	if(tree)
	{
		printf("%d\n",tree->data);
		preOrder(tree->leftChild);
		preOrder(tree->rightChild);
	}
}
void postOrder(node *tree)
{
	if(tree)
	{
		postOrder(tree->leftChild);
		postOrder(tree->rightChild);
		printf("%d\n",tree->data);
	}
}
void lazyDelete(node *tree,int val)
{
	if(tree)
	{
		if(tree->data==val)
			tree->data=0;
		else if(val<tree->data)
			search(tree->leftChild,val);
		else
			search(tree->rightChild,val);
	}
}
int main()
{
	node *root;
	int n,choice;
	printf("Input number of nodes\n");
	scanf("%d",&n);
	printf("Insert into BST\n");
	root=NULL;
	while(n--)
	{
		node *temp;
		temp=(node *)malloc(sizeof(node));
		scanf("%d",&temp->data);
		temp->leftChild=temp->rightChild=NULL;
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);
	}
	printf("Enter search value\n");
	scanf("%d",&n);
	search(root,n);
	printf("Enter value to delete\n");
	scanf("%d",&n);
	lazyDelete(root,n);
	printf("In-order printing\n");
	inOrder(root);
	printf("Pre-order printing\n");
	preOrder(root);
	printf("Post-order printing\n");
	postOrder(root);
	return 0;
}
