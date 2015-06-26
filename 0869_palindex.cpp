#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[100001];
		scanf("%s", s);
		int start = 0, end = strlen(s) - 1;
		int ans = -1;
		while (start < end)
		{
			if (s[start] == s[end])
				start++, end--;
			else if (s[start + 1] == s[end])
			{
				printf("%d\n", start);
				break;
			}
			else
			{
				printf("%d\n", end);
				break;
			}
		}
		if (start >= end)
			puts("-1");
	}
	return 0;
}
