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
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		int possible = true;
		for (int i = 1; i < (int) v.size() and possible; i++)
			if (v[i] == v[i - 1])
				possible = false;
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
