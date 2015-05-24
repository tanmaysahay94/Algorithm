#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<int> c(n+1);
		int sum = 0, possible = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &c[i]);
			sum += c[i];
			if (c[i] > n - 1)
				possible = 0;
		}
		if (sum != n or not possible)
		{
			printf("-1\n");
			continue;
		}
		vector<int> ans(n+1), havevotes;
		for (int i = 1; i <= n; i++)
			if (c[i])
				havevotes.push_back(i);
		for (int i = 0; i < (int) havevotes.size(); i++)
		{
			ans[havevotes[i]] = havevotes[(i + 1) % havevotes.size()];
			c[havevotes[(i + 1) % havevotes.size()]]--;
		}
		int votefor;
		for (int i = 1; i <= n; i++)
			if (c[i])
			{
				votefor = i;
				break;
			}
		if (votefor)
		{
			for (int i = 1; i <= n; i++)
			{
				if (not ans[i])
				{
					ans[i] = votefor;
					c[votefor]--;
					if (not c[votefor])
					{
						votefor++;
						for (; votefor <= n; votefor++)
							if (c[votefor])
								break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
