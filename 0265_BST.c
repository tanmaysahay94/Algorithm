#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *leftChild,*rightChild;
}node;
void insert(node *tree,node *leaf)
{
	if(tree==NULL)					//base case for the recursion
		tree=leaf;
	else
	{
		if(tree->data<leaf->data)
			insert(tree->leftChild,leaf);
		else
			insert(tree->rightChild,leaf);
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
	delete(root,n);
	printf("In-order printing\n");
	inOrder(root);
	printf("Pre-order printing\n");
	preOrder(root);
	printf("Post-order printing\n");
	postOrder(root);
	return 0;
}
