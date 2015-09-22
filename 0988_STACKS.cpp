#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		multiset<int> m;
		for (int i = 0; i < n; i++)
		{
			int rad;
			scanf("%d", &rad);
			multiset<int>::iterator it = m.upper_bound(rad);
			if (it == m.end())
				m.insert(rad);
			else
			{
				m.erase(it);
				m.insert(rad);
			}
		}
		printf("%d ", (int) m.size());
		for (auto foo: m)
			printf("%d ", foo);
		printf("\n");
	}
	return 0;
}
