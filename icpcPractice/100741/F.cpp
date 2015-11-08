#include <bits/stdc++.h>

using namespace std;

const int maxn = 305;

int n;
bool possible = false;
unordered_map<int, unordered_set<int> > mp;
vector<int> sol;

int diagonal(int i, int j)
{
	return n - (i - j);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int val;
			scanf("%d", &val);
			mp[diagonal(i, j) - 1].insert(val);
		}
	/*
	 * magic
	 */
	if (possible)
	{
		printf("YES\n");
		for (auto s: sol)
			printf("%d ", s);
	}
	else
		printf("NO");
	return 0;
}
