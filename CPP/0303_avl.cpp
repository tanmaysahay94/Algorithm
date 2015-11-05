#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

using namespace std;

template <class T>
class avlTree; 

//#---------------------------------------Node Declaration------------------------------------#
template <class T>
struct avl_node
{
	class avlTree<T>;
	T data;
	struct avl_node<T> *left;
	struct avl_node<T> *right;
};

//#---------------------------------------Class Declaration------------------------------------#
template <class T>
class avlTree
{
	public:
		avl_node<T> *root;
		int height(avl_node<T> *);
		int diff(avl_node<T> *);
		avl_node<T> *rr_rotation(avl_node<T> *);
		avl_node<T> *ll_rotation(avl_node<T> *);
		avl_node<T> *lr_rotation(avl_node<T> *);
		avl_node<T> *rl_rotation(avl_node<T> *);
		avl_node<T> *balance(avl_node<T> *,const T);
		avl_node<T> *insert(const T );
		avl_node<T> *remove(const T);
		avl_node<T> *lookup(const T );
		avl_node<T> *minValueNode(avl_node<T> *);
		void inorder(avl_node<T> *);
		void preorder(avl_node<T> *);
		void postorder(avl_node<T> *);
		avlTree()  
		{
			root = NULL;
		}
};

int main()
{
	int choice, item;
	avlTree <int> avl;
	while (1)
	{
		cout<<"\nAVL Tree Implementation"<<endl;
		cout<<"---------------------"<<endl;
		cout<<"1.Insert Element into the tree"<<endl;
		cout<<"2.InOrder traversal"<<endl;
		cout<<"3.PreOrder traversal"<<endl;
		cout<<"4.PostOrder traversal"<<endl;
		cout<<"5.Search"<<endl;
		cout<<"6.Delete"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter value to be inserted: ";
				cin>>item;
				avl.insert(item);
				break;
			case 2:
				cout<<"\n---------------------\n"<<endl;
				cout<<"Inorder Traversal: ";
				avl.inorder(avl.root);
				cout<<"\n---------------------\n"<<endl;
				cout<<endl;
				break;
			case 3:
				cout<<"\n---------------------\n"<<endl;
				cout<<"Preorder Traversal: ";
				avl.preorder(avl.root);
				cout<<"\n---------------------\n"<<endl;
				cout<<endl;
				break;
			case 4:
				cout<<"\n---------------------\n"<<endl;
				cout<<"Postorder Traversal: ";
				avl.postorder(avl.root);    
				cout<<"\n---------------------\n"<<endl;
				cout<<endl;
				break;
			case 5:
				cout<<"Value to be Searched: ";
				cin>>item;
				cout<<"\n---------------------\n"<<endl;
				if(avl.lookup(item) == NULL)
					cout<<"Not found";
				else
					cout<<"Found";
				cout<<"\n---------------------\n"<<endl;
				break;
			case 6:
				cout<<"Enter value to be deleted: ";
				cin>>item;
				avl.remove(item);
				break;
			case 7:
				exit(1);    
				break;
			default:
				cout<<"Wrong Choice"<<endl;
		}
	}
	return 0;
}

//#--------------------------------------Height of AVL Tree-----------------------------------#
	template <class T>
int avlTree<T>::height(avl_node<T> *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height (temp->left);
		int r_height = height (temp->right);
		int max_height = max (l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

//#-----------------------------------------Height Difference---------------------------------#
	template <class T>
int avlTree<T>::diff(avl_node<T> *temp)
{
	int l_height = height (temp->left);
	int r_height = height (temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

//#------------------------------------Right- Right Rotation-----------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::rr_rotation(avl_node<T> *parent)
{
	avl_node<T> *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

//#------------------------------------Left- Left Rotation-------------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::ll_rotation(avl_node<T> *parent)
{
	avl_node<T> *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

//#-----------------------------------Left - Right Rotation------------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::lr_rotation(avl_node<T> *parent)
{
	avl_node<T> *temp;
	temp = parent->left;
	parent->left = rr_rotation (temp);
	return ll_rotation (parent);
}

//#-----------------------------------Right- Left Rotation-------------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::rl_rotation(avl_node<T> *parent)
{
	avl_node<T> *temp;
	temp = parent->right;
	parent->right = ll_rotation (temp);
	return rr_rotation (parent);
}

//#-------------------------------------Balancing AVL Tree-------------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::balance(avl_node<T> *temp_new,const T value)
{
	int bal_factor = diff (temp_new);

	if (bal_factor > 1)
	{
		if (diff (temp_new->left) > 0)
			temp_new = ll_rotation (temp_new);
		else
			temp_new = lr_rotation (temp_new);
	}
	else if (bal_factor < -1)
	{
		if (diff (temp_new->right) > 0)
			temp_new = rl_rotation (temp_new);
		else
			temp_new = rr_rotation (temp_new);
	}
	// Traversing further down to balance the tree at the node
	// where it isn't
	else
	{
		if(temp_new->data > value)
			temp_new->left = balance(temp_new->left,value);

		else if(temp_new->data < value)
			temp_new->right = balance(temp_new->right,value);
	}

	return temp_new;
}

//#-----------------------------------Insert Element into the tree-----------------------------#
	template <class T>
avl_node<T> *avlTree<T>::insert(const T value)
{
	// In case the tree is empty
	if (root == NULL)
	{
		root = new avl_node<T>;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	avl_node<T> *temp;
	temp = new avl_node<T>;
	temp = root;
	avl_node<T> *parent;
	parent = new avl_node<T>;
	parent = root;

	while(1)
	{
		// Point of insertion found
		if (temp == NULL)
		{
			temp = new avl_node<T>;
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;

			// Linkng the parent with its new child
			if(parent->data > value)
				parent->left = temp;
			else if(parent->data < value)
				parent->right = temp;

			// Restoring the balance of the AVL tree
			root = balance(root,value);

			return temp;
		}
		// Further traversing to find the point of inserton
		else if (value < temp->data)
		{
			parent = temp;
			temp = temp->left;
		}
		else if (value >= temp->data)
		{
			parent = temp;
			temp = temp->right;
		}

		// Node with the value to be inserted already exists in the tree
		else				
			return temp;
	}
}

//#---------------------------------Inorder Traversal of AVL Tree-----------------------------#
	template <class T>
void avlTree<T>::inorder(avl_node<T> *root)
{
	if (root == NULL)
		return;
	inorder (root->left);
	cout<< root->data << "  ";
	inorder (root->right);
}

//#--------------------------------Preorder Traversal of AVL Tree-----------------------------#
	template <class T>
void avlTree<T>::preorder(avl_node<T> *root)
{
	if (root == NULL)
		return;
	cout<< root->data <<"  ";
	preorder (root->left);
	preorder (root->right);

}

//#-------------------------------Postorder Traversal of AVL Tree-----------------------------#
	template <class T>
void avlTree<T>::postorder(avl_node<T> *root)
{
	if (root == NULL)
		return;
	postorder ( root ->left );
	postorder ( root ->right );
	cout<< root->data << "  ";
}

//#--------------------------------------Search for a given node-------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::lookup(const T value)
{
	avl_node<T> *temp;
	temp = new avl_node<T>;
	temp = root;
	// Implement a simple recursive search
	while(1)
	{
		if(temp == NULL)
			return NULL;
		else if(temp->data == value)
			return temp;
		else if(temp->data > value)
			temp = temp-> left; 
		else
			temp = temp-> right;
	}
}

//#-----------------------Obtain the node with minimum value in a given subtree----------------#
	template <class T>
avl_node<T> *avlTree<T>::minValueNode(avl_node<T> *node)
{
	avl_node<T> *current = node;

	// Loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

//#-------------------------------------------Remove a node-----------------------------------#
	template <class T>
avl_node<T> *avlTree<T>::remove(const T key)
{
	// In case tree is empty
	if (root == NULL)
		return root;

	avl_node<T> *temp, *parent;
	parent =  new avl_node<T>;
	temp =  new avl_node<T>;
	temp = root;

	while(1)
	{
		// Node not present in tree
		if(temp == NULL)
			return NULL;

		// Searching for the node to be deleted
		if ( key < temp->data )
		{
			parent = temp;
			temp = temp->left;
		}
		else if( key > temp->data )
		{
			parent = temp;
			temp = temp->right;
		}

		// Node to be deleted found
		else
		{
			// Node with only one child or no child
			if( (temp->left == NULL) || (temp->right == NULL) )
			{
				avl_node<T> *temp_new;
				temp_new =  new avl_node<T>;
				temp_new = temp->left ? temp->left : temp->right;

				// No child case
				if(temp_new == NULL)
				{
					// When the node to be removed is the last node of the tree
					if(temp->data == root->data)
						root = NULL;

					// Removing the linkage between parent and it's child node
					// which is to be deleted
					if(parent->data > key)
						parent->left = NULL;
					else
						parent->right = NULL;
					temp_new = temp;
					temp = NULL;
				}
				// One child case
				else 				
					*temp = *temp_new;  // Copy the contents of the non-empty child

				delete temp_new;

				// Breaking out of the loop, as the value has been deleted
				break;
			}
			else
			{
				// Node with two children: Get the inorder successor (smallest
				// in the right subtree)
				avl_node<T> *temp_new = minValueNode(temp->right);

				// Removing the inorder successor as that has to be copied into
				// the node to be deleted
				T val = temp_new->data;
				remove(val);

				// Copy the inorder successor's data to this node
				temp->data = val;

				// Breaking out of the loop, as the value has been deleted
				break;
			}
		}
	}
	// Restoring the balance of the tree
	if(root == NULL)
		return NULL;
	else
		root = balance(root,root->data);
}
