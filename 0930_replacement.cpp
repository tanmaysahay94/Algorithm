#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	char s[300005];
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (s[i] == '.' and s[i + 1] == '.')
			ans++;
	for (int i = 0; i < m; i++)
	{
		int idx;
		char ch;
		scanf("%d %c", &idx, &ch);
		getchar();
		if (s[idx] == '.' and s[idx - 1] == '.')
			ans--;
		if (s[idx] == '.' and s[idx + 1] == '.')
			ans--;
		s[idx] = ch;
		if (s[idx] == '.' and s[idx - 1] == '.')
			ans++;
		if (s[idx] == '.' and s[idx + 1] == '.')
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}
