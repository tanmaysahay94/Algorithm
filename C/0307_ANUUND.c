#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int a[n];
		for (i = 0; i < n; i++)
			scanf("%d", a+i);
		qsort(a, n, sizeof(int), cmp);
		for (i = 0, j = n-1; i < j; i++, j--)
			printf("%d %d ", a[i], a[j]);
		if (i == j)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
