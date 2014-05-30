#include <stdio.h>
#include <stdlib.>

typedef struct node
{
	int val, loc;
}node;

int cmp(const void *a, const void *b)
{
	return (*(node *)b).val - (*(node *)a).val;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	node v[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v[i].val);
		v[i].loc = i;
	}
	qsort(v, n, sizeof(node), cmp);
}
