#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	//	optimizeIO();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int a[n], foo[11] = {0};
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			foo[a[i] % (k + 1)]++;
		}
		int cnt = 0;
		for (int i = 0; i < 11; i++)
			if (foo[i])
				cnt++;
		if (cnt == 1)
			printf("YES\n");
		else if (cnt == 2)
		{
			for (int i = 0; i < 11; i++)
				if (foo[i])
				{
					if (foo[i] == 1 or foo[i] == n - 1)
						printf("YES\n");
					else
						printf("NO\n");
					break;
				}
		}
		else
			printf("NO\n");
	}
	return 0;
}
