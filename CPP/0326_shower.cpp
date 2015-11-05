#include <iostream>
#include <algorithm>
using namespace std;

long long max(long long a, long long b)
{
	return a > b ? a : b;
}
int main()
{
	long long i, j, a, b, c, d, e, g[5][5], happiness = 0;
	long long people[5] = {0, 1, 2, 3, 4};
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			cin >> g[i][j];
	do
	{
		a = people[0];
		b = people[1];
		c = people[2];
		d = people[3];
		e = people[4];
		happiness = max(happiness, g[a][b] + g[b][a] + 2 * g[c][d] + 2 * g[d][c] + g[b][c] + g[c][b] + 2 * g[d][e] + 2 *g[e][d]);
	}while (next_permutation(people, people + 5));
	cout << happiness << endl;
}
