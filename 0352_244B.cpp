#include <cstdio>

using namespace std;

int main()
{
	long n, t, c, i, s, curr = 0, total = 0;
	scanf("%ld%ld%ld", &n, &t, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &s);
		if (s <= t) curr++;
		else
		{
			if (curr >= c)
				total += curr - c + 1;
			curr = 0;
		}
	}
	if (curr >= c) total += curr -c + 1;
	curr = 0;
	printf("%ld\n", total);
}
