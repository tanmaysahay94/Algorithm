#include <bits/stdc++.h>

using namespace std;

const int fix = 2000005;
const int maxn = 200005;
char s[2][maxn];
int len;

int f(int w)
{
	if (s[w][0] == '#')
		return fix;
	int ret = 0;
	int i = 0;
	while (i + 1 < len)
		if (s[w][i + 1] == '.')
			i++;
		else if (s[w ^ 1][i + 1] == '.')
			w ^= 1, i++, ret++;
		else
			return fix;
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", s[0], s[1]);
		len = strlen(s[1]);
		int ans = min(f(0), f(1));
		if (ans != fix)
			printf("Yes\n%d\n", ans);
		else
			printf("No\n");
	}
	return 0;
}
