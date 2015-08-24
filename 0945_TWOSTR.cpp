#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[15], b[15];
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", a, b);
		bool match = true;
		for (int i = 0; a[i]; i++)
			if (a[i] != '?' and b[i] != '?' and a[i] != b[i])
				match = false;
		if (match)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
