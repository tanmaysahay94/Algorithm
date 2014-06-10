#include <cstdio>

using namespace std;

int main()
{
	int u = 0, p = 0, v, n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &v);
		if (v > 0) p += v;
		else if (p) p--;
		else u++;
	}
	printf("%d\n", u);
}
