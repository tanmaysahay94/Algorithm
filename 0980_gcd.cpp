#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 1)
	{
		if (k)
			printf("-1");
		else
			printf("1");
		return 0;
	}
	int p = n / 2;
	if (k < p)
	{
		printf("-1");
		return 0;
	}
	else
	{
		int i = 1, j = 1;
		for (; i < p; i++, j += 2)
			printf("%d %d ", j, j + 1);
		int foo = 0;
		int step = k - p + 1;
		while (foo < j)
			foo += step;
		printf("%d %d ", foo, foo + step);
		if (n & 1)
			printf("%d", foo + step + 1);
	}
	return 0;
}
