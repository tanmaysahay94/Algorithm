#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[1000005];
	scanf("%s", s);
	int n = strlen(s);
	vector<int> v(n);
	int l = 0, r = n - 1;
	for (int i = 0; s[i]; i++)
		if (s[i] == 'l')
			v[r--] = i + 1;
		else
			v[l++] = i + 1;
	for (auto f: v)
		printf("%d\n", f);
	return 0;
}
