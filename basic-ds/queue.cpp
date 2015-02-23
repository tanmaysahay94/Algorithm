#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

node *newNode(int val)
{
	node *tmp = (node *) malloc (sizeof(node));
	tmp->val = val;
	tmp->next = NULL;
	return tmp;
}

node *head;
node *tail;

void push(int val)
{
	if (head == NULL && head == tail)
		head = tail = newNode(val);
	else
	{
		node *temp = newNode(val);
		tail->next = temp;
		tail = tail->next;
	}
}

int pop()
{
	if (head == NULL)
		return -1;
	int ret = head->val;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	return ret;
}

int main()
{
	char choice;
	head = tail = NULL;
	do {
		int ch;
		printf("1. Push\n2. Pop\n3. Exit\n");
		scanf("%d", &ch);
		if (ch == 1)
		{
			int val;
			printf("Input element into the queue\n");
			scanf("%d", &val);
			push(val);
		}
		else if (ch == 2)
			printf("The popped element is %d\n", pop());
		else
			break;
		printf("Press 'y' to continue\n");
		getchar();
		scanf("%c", &choice);
	} while (choice == 'y');
	return 0;
}
