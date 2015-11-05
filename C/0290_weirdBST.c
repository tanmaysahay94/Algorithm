#include<stdio.h>
#include<stdlib.h>
int Arr[100000],count;
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
node *newNode(int val)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}
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
void preOrder(node *tree)
{
	if(tree)
	{
		Arr[count++]=tree->data;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
void inOrder(node *tree)
{
	if(tree)
	{
		inOrder(tree->left);
		Arr[count++]=tree->data;
		inOrder(tree->right);
	}
}
void postOrder(node *tree)
{
	if(tree)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		Arr[count++]=tree->data;
	}
}
node *leftRotate(node *tree)
{
	node *x=tree->left,*temp;
	temp=tree;
	temp->left=x->right;
	x->right=temp;
	return x;
}
node *rightRotate(node *tree)
{
	node *x=tree->right,*temp;
	temp=tree;
	temp->right=x->left;
	x->left=temp;
	return x;
}
node *withNewRoot(node *tree,int val)
{
	if(val<tree->data)
		tree->left=withNewRoot(tree->left,val);
	else if(val>tree->data)
		tree->right=withNewRoot(tree->right,val);
	if(tree->left&&tree->left->data==val)
		tree=leftRotate(tree);
	else if(tree->right&&tree->right->data==val)
		tree=rightRotate(tree);
	return tree;
}
void print(int array[],int size)
{
	int i;
	for(i=0;i<size-1&&printf("%d ",array[i]);i++);
	printf("%d\n",array[i]);
}
int main()
{
	int t,n,i,num;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		node *root=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(!root)
				root=newNode(num);
			else
				insert(root,newNode(num));
		}
		for(i=0;i<n;i++)
			scanf("%d",&num);
		scanf("%d",&num);
		if(root->data!=num)
			root=withNewRoot(root,num);
		inOrder(root);
		print(Arr,count);
		count=0;
		preOrder(root);
		print(Arr,count);
		count=0;
		postOrder(root);
		print(Arr,count);
	}
	return 0;
}
