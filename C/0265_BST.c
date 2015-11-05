#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
void insert(node *tree,node *leaf)
{
	if(tree->data>leaf->data)
		if(tree->left==NULL)
			tree->left=leaf;
		else
			insert(tree->left,leaf);
	else
		if(tree->right==NULL)
			tree->right=leaf;
		else
			insert(tree->right,leaf);
}
int search(node *tree,int val)
{
	if(tree)
		if(tree->data==val)
			return 1;
		else
			if(val>tree->data)
				search(tree->right,val);
			else
				search(tree->left,val);
	else
		return 0;
}
void inOrder(node *tree)
{
	if(tree)
	{
		inOrder(tree->left);
		printf("%d ",tree->data);
		inOrder(tree->right);
	}
}
void preOrder(node *tree)
{
	if(tree)
	{
		printf("%d ",tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
void postOrder(node *tree)
{
	if(tree)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		printf("%d ",tree->data);
	}
}
void lazyDelete(node *tree,int val)
{
	if(tree)
		if(tree->data==val)
			tree->data=0;
		else if(val<tree->data)
			lazyDelete(tree->left,val);
		else
			lazyDelete(tree->right,val);
}
node *min(node *tree)
{
	while(tree->left)
		tree=tree->left;
	return tree;
}
node *delete(node *tree,int val)
{
	node *temp=(node *)malloc(sizeof(node));
	if(val<tree->data)
		tree->left=delete(tree->left,val);
	else if(val>tree->data)
		tree->right=delete(tree->right,val);
	else
	{
		if(tree->left&&tree->right)
		{
			temp=min(tree->right);
			tree->data=temp->data;
			tree->right=delete(tree->right,val);
		}
		else if(tree->right)
			tree=tree->right;
		else
			tree=tree->left;
	}
	return tree;
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
		temp->left=temp->right=NULL;
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);
	}
	printf("Enter search value\n");
	scanf("%d",&n);
	printf("%d\n",search(root,n));
	printf("Enter value to delete\n");
	scanf("%d",&n);
	delete(root,n);
	printf("In-order printing\n");
	inOrder(root);
	printf("\n");
	printf("Pre-order printing\n");
	preOrder(root);
	printf("\n");
	printf("Post-order printing\n");
	postOrder(root);
	printf("\n");
	return 0;
}
