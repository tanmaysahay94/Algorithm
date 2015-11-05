#include <stdio.h>
#include <stdlib.h>
struct AVLTree_Node
{
	int data, bfactor;
	struct AVLTree_Node *link[2];
};
struct AVLTree_Node *root = NULL;
int output[100000], outputCount = 0;
struct AVLTree_Node * createNode(int data) 
{
	struct AVLTree_Node *newnode;
	newnode = (struct AVLTree_Node *)malloc(sizeof (struct AVLTree_Node));
	newnode->data    = data;
	newnode->bfactor = 0;
	newnode->link[0] = newnode->link[1] = NULL;
	return newnode;
}
void insertion (int data) 
{
	struct AVLTree_Node *bf, *parent_bf, *subtree, *temp;
	struct AVLTree_Node *current, *parent, *newnode, *ptr;
	int res = 0, link_dir[32], i = 0;
	if (!root) 
	{
		root = createNode(data);
		return;
	}
	bf = parent_bf = root;
	/* find the location for inserting the new node*/
	for (current = root; current != NULL; ptr = current, current = current->link[res])
	{
		if (data == current->data) 
			return;
		res = (data > current->data) ? 1 : 0;
		parent = current;
		if (current->bfactor != 0) 
		{
			bf = current;
			parent_bf = ptr;
			i = 0;
		}
		link_dir[i++] = res;
	}
	/* create the new node */
	newnode = createNode(data);
	parent->link[res] = newnode;
	res = link_dir[i = 0];
	/* updating the height balance after insertion */
	for (current = bf; current != newnode; res = link_dir[++i]) 
	{
		if (res == 0)
			current->bfactor--;
		else
			current->bfactor++;
		current = current->link[res];
	}
	/* right sub-tree */
	if (bf->bfactor == 2) 
	{
		temp = bf->link[1];
		if (temp->bfactor == 1) 
		{
			subtree = temp;
			bf->link[1] = temp->link[0];
			temp->link[0] = bf;
			temp->bfactor = bf->bfactor = 0;
		} 
		else 
		{
			subtree = temp->link[0];
			temp->link[0] = subtree->link[1];
			subtree->link[1] = temp;
			bf->link[1] = subtree->link[0];
			subtree->link[0] = bf;
			/* update balance factors */
			if (subtree->bfactor == -1) 
			{
				bf->bfactor = 0;
				temp->bfactor = 1;
			} 
			else if (subtree->bfactor == 0) 
			{
				bf->bfactor = 0;
				temp->bfactor = 0;
			} 
			else if (subtree->bfactor == 1) 
			{
				bf->bfactor = -1;
				temp->bfactor = 0;
			}
			subtree->bfactor = 0;
		}
		/* left sub-tree */
	} 
	else if (bf->bfactor == -2) 
	{
		temp = bf->link[0];
		if (temp->bfactor == -1) 
		{
			subtree = temp;
			bf->link[0] = temp->link[1];
			temp->link[1] = bf;
			temp->bfactor = bf->bfactor = 0;
		} 
		else 
		{
			subtree = temp->link[1];
			temp->link[1] = subtree->link[0];
			subtree->link[0] = temp;
			bf->link[0] = subtree->link[1];
			subtree->link[1] = bf;
			/* update balance factors */
			if (subtree->bfactor == -1) 
			{
				bf->bfactor = 1;
				temp->bfactor = 0;
			} 
			else if (subtree->bfactor == 0) 
			{
				bf->bfactor = 0;
				temp->bfactor = 0;
			} 
			else if (subtree->bfactor == 1) 
			{
				bf->bfactor = 0;
				temp->bfactor = -1;
			}
			subtree->bfactor = 0;
		}
	} 
	else 
		return;
	if (bf == root) 
	{
		root = subtree;
		return;
	}
	if (bf != parent_bf->link[0]) 
		parent_bf->link[1] = subtree;
	else 
		parent_bf->link[0] = subtree;
	return;
}
void deletion(int data) 
{
	int link_dir[32], res = 0, i = 0, j = 0, index = 0;
	struct AVLTree_Node *ptr[32], *current, *temp, *x, *y, *z;
	current = root;
	if (!root) 
		return;
	if ((root->data == data) && (root->link[0] == NULL) && (root->link[1] == NULL)) 
	{
		free(root);
		root = NULL;
		return;
	}
	/* search the node to delete */
	while (current != NULL) 
	{
		if (current->data == data)
			break;
		res = data > current->data ? 1 : 0;
		link_dir[i] = res;
		ptr[i++] = current;
		current = current->link[res];
	}
	if (!current) 
		return;
	index = link_dir[i - 1];
	temp = current->link[1];
	/* delete the node from the AVL tree - similar to BST deletion */
	if (current->link[1] == NULL) 
	{
		if (i == 0) 
		{
			temp = current->link[0];
			free(current);
			root = temp;
			return;
		} 
		else 
			ptr[i - 1]->link[index] = current->link[0];
	} 
	else if (temp->link[0] == NULL) 
	{
		temp->link[0] = current->link[0];
		temp->bfactor = current->bfactor;
		if (i > 0) 
			ptr[i-1]->link[index] = temp;
		else 
			root = temp;
		link_dir[i] = 1;
		ptr[i++] = temp;
	} 
	else 
	{
		/* delete node with two children */
		j = i++;
		while (1) 
		{
			link_dir[i] = 0;
			ptr[i++] = temp;
			x = temp->link[0];
			if (x->link[0] == NULL)
				break;
			temp = x;
		}
		x->link[0] = current->link[0];
		temp->link[0] = x->link[1];
		x->link[1] = current->link[1];
		x->bfactor = current->bfactor;
		if (j > 0) 
			ptr[j - 1]->link[index] = x;
		else 
			root = x;
		link_dir[j] = 1;
		ptr[j] = x;
	}
	free(current);
	for (i = i - 1; i >= 0; i = i--) 
	{
		x = ptr[i];
		if (link_dir[i] == 0) 
		{
			x->bfactor++;
			if (x->bfactor == 1) 
				break;
			else if (x->bfactor == 2) 
			{
				y = x->link[1];
				if (y->bfactor == -1) 
				{
					/* double rotation - (SR right + SR left) */
					z = y->link[0];
					y->link[0] = z->link[1];
					z->link[1] = y;
					x->link[1] = z->link[0];
					z->link[0] = x;
					/* update balance factors */
					if (z->bfactor == -1) 
					{
						x->bfactor = 0;
						y->bfactor = 1;
					} else if (z->bfactor == 0) 
					{
						x->bfactor = 0;
						y->bfactor = 0;
					} 
					else if (z->bfactor == 1) 
					{
						x->bfactor = -1;
						y->bfactor = 0;
					}
					z->bfactor = 0;
					if (i > 0) 
					{
						index = link_dir[i - 1];
						ptr[i - 1]->link[index] = z;
					} 
					else 
						root = z;
				} 
				else 
				{
					/* single rotation left */
					x->link[1] = y->link[0];
					y->link[0] = x;
					if (i > 0) 
					{
						index = link_dir[i - 1];
						ptr[i - 1]->link[index] = y;
					} 
					else  
						root = y;
					/* update balance factors */
					if (y->bfactor == 0) 
					{
						x->bfactor = 1;
						y->bfactor = -1;
						break;
					} 
					else 
					{
						x->bfactor = 0;
						y->bfactor = 0;
					}
				}
			}
		} 
		else 
		{
			x->bfactor--;
			if (x->bfactor == -1) 
				break;
			else if (x->bfactor == -2) 
			{
				y = x->link[0];
				if  (y->bfactor == 1) 
				{
					/* double rotation - (SR right + SR left) */
					z = y->link[1];
					y->link[1] = z->link[0];
					z->link[0] = y;
					x->link[0] = z->link[1];
					z->link[1] = x;
					/* update balance factors */
					if (z->bfactor == -1) 
					{
						x->bfactor = 1;
						y->bfactor = 0;
					} 
					else if (z->bfactor == 0) 
					{
						x->bfactor = 0;
						y->bfactor = 0;
					} 
					else if (z->bfactor == 1) 
					{
						x->bfactor = 0;
						y->bfactor = -1;
					}
					z->bfactor = 0;
					if (i > 0) 
					{
						index = link_dir[i - 1];
						ptr[i - 1]->link[index] = z;
					} 
					else 
						root = z;
				} 
				else 
				{
					/* single rotation right */
					x->link[0] = y->link[1];
					y->link[1] = x;
					if (i <= 0) 
						root = y;
					else 
					{
						index = link_dir[i - 1];
						ptr[i - 1]->link[index] = y;
					}
					/* update balance factors */
					if (y->bfactor == 0) 
					{
						x->bfactor = -1;
						y->bfactor = 1;
						break;
					} 
					else 
					{
						x->bfactor = 0;
						y->bfactor = 0;
					}
				}
			}
		}
	}
}
void inorderTraversal(struct AVLTree_Node *myNode) 
{
	if (myNode) 
	{
		output[outputCount++] = myNode->data;
		inorderTraversal(myNode->link[0]);
		inorderTraversal(myNode->link[1]);
	}
	return;
}
int main() 
{
	int t, numQ, key, i;
	char choice, garbage;
	scanf("%d", &t);
	while (t--)
	{
		root = NULL;
		scanf("%d", &numQ);
		while (numQ--)
		{
			scanf("%c%c", &garbage, &choice);
			if (choice == 'i')
			{
				scanf("%d", &key);
				insertion(key);
			}
			else if(choice == 'd')
			{
				scanf("%d",&key);
				deletion(key);
			}
			else if(choice == 'p')
			{
				if(root)
				{
					outputCount = 0;
					inorderTraversal(root);
					for(i = 0; i < outputCount - 1; i++)
						printf("%d ", output[i]);
					printf("%d\n", output[i]);
				}
				else
					printf("\n");
			}
		}
	}
	return 0;
}
