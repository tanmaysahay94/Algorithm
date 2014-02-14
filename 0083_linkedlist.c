#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int n;
	struct list *next;
}node;
int main()
{
	node *start;
	start=(node*)malloc(sizeof(node));
	(*start).n=4; // or start -> n = 4
	(*start).next=(node*)malloc(sizeof(node));
	start->next->n=5;
	start->next->next=NULL;
	return 0;
}
