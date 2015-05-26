#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
/*	optimizeIO();*/
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, d;
		set<int> s;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &d);
			s.insert(d);
		}
		printf("%d\n", (int) s.size());
	}
	return 0;
}
