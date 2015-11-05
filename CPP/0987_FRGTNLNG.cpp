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
		vector<string> words;
		for (int i = 0; i < n; i++)
		{
			string foo;
			cin >> foo;
			words.push_back(foo);
		}
		set<string> lookHere;
		for (int i = 0; i < k; i++)
		{
			int l;
			scanf("%d", &l);
			for (int j = 0; j < l; j++)
			{
				string foo;
				cin >> foo;
				lookHere.insert(foo);
			}
		}
		for (auto foo: words)
			if (lookHere.count(foo))
				printf("YES ");
			else
				printf("NO ");
		printf("\n");
	}
	return 0;
}
