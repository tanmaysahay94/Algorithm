#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

node *newNode(int val)
{
	node *temp = (node *) malloc (sizeof(node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

node *TOP;

void push(int val)
{
	if (TOP == NULL)
		TOP = newNode(val);
	else
	{
		node *temp = newNode(val);
		temp->next = TOP;
		TOP = temp;
	}
}

int top()
{
	if (TOP == NULL)
		return -1;
	return TOP->val;
}

int pop()
{
	int ret = top();
	if (TOP != NULL)
		TOP = TOP->next;
	return ret;
}

int main()
{
	TOP = NULL;
	char choice;
	do {
		printf("1. Push\n2. Pop\n3. Top Value\n4. Exit\n");
		int ch;
		scanf("%d", &ch);
		if (ch == 1)
		{
			int val;
			printf("Value to be pushed onto the stack: ");
			scanf("%d", &val);
			push(val);
		}
		else if (ch == 2)
			printf("Value popped from stack is %d\n", pop());
		else if (ch == 3)
			printf("Value at the top of the stack is %d\n", top());
		else
			break;
		getchar();
		printf("Press 'y' to continue\n");
		scanf("%c", &choice);
	} while (choice == 'y');
	return 0;
}
