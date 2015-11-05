#include <cstdio>
#include <vector>

using namespace std;

typedef int ULL;

int main()
{
	ULL p, n, i, ans = -1, val;
	scanf("%d%d", &p, &n);
	vector<bool> v(p, false);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val);
		val %= p;
		if (not v[val])
			v[val] = true;
		else
		{
			ans = i;
			break;
		}
	}
	for (i = i; i <= n; i++)
		scanf("%d", &val);
	printf("%d\n", ans);
	return 0;
}
