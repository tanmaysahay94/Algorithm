#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int val;
			scanf("%d", &val);
			if ((val + k) % 7 == 0)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
