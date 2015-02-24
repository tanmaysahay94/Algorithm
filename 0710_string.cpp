#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	char s[111], t[111], ss[111];
	scanf("%s%s", ss, t);
	int l = strlen(ss);
	int carry = 1;
	for (int i = l - 1; i >= 0; i--)
		s[i] = ss[i];
	s[l] = '\0';
	for (int i = l - 1; i >= 0 and carry; i--)
	{
		s[i] += carry;
		if (s[i] > 'z')
			s[i] = 'z';
		else
			carry = 0;
	if (strcmp(s, ss) > 0 and strcmp(s, t) < 0)
		printf("%s\n", s);
	else
		printf("No such string\n");
	return 0;
}
