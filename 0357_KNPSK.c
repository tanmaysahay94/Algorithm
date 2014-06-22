#include <stdio.h>
#include <stdlib.h>

typedef struct obj
{
	unsigned long long wt, cost;
}obj;

int cmp(const void *a, const void *b)
{
	if ((*(obj *)a).wt == (*(obj *)b).wt)
		return (*(obj *)b).cost - (*(obj *)a).cost;
	return (*(obj *)a).wt - (*(obj *)b).wt;
}

int main()
{
	unsigned long long i, n, weight, max_weight = 0;
	scanf("%llu", &n);
	obj o[n];
	unsigned long long weight[200005] = {0};
	for (i = 0; i < n; i++)
	{
		scanf("%llu%llu", &o[i].wt, &o[i].cost);
		max_weight += o[i].wt;
	}
	qsort(o, n, sizeof(obj), cmp);
	for (weight = 1; weight <= max_weight; weight++)
	{
	}
}
