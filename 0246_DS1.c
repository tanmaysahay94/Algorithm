#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int n, c, d, swap;
	srand(time(NULL));
	n = 1000000;
	int array[n];
	for (c = 0; c < n; c++)
		array[c] = rand()%1000;
	for (c = 0 ; c < ( n - 1 ); c++)
		for (d = 0 ; d < n - c - 1; d++)
			if (array[d] > array[d+1]) /* For decreasing order use < */
			{
				swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
			}
	return 0;
}
