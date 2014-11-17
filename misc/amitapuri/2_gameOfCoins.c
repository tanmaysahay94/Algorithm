#include <stdio.h>

long long win[2];
void game(long long n, long long player)
{
	if (n == 0)
	{
		win[!player]++;
		return;
	}
	game(n - 1, !player);
	if (n > 1)
		game(n - 2, !player);
}

int main()
{
	long long t, n, k;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &k);
		k--;
		win[0] = win[1] = 0;
		game(n, k);
		printf("%lld %lld\n", win[0], win[1]);
	}
}
