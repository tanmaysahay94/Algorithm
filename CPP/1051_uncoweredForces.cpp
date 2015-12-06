#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m[5], w[5], s, u;
	for (int i = 0; i < 5; i++)
		scanf("%d", &m[i]);
	for (int i = 0; i < 5; i++)
		scanf("%d", &w[i]);
	scanf("%d%d", &s, &u);
	int ans = 0;
	for (int i = 0, x = 500; i < 5; i++, x += 500)
		ans += max(3 * x / 10, ((250 - m[i]) * x) / 250 - 50 * w[i]);
	ans += 100 * s - 50 * u;
	printf("%d\n", ans);
	return 0;
}
