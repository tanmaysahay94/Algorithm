#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int n, p1, p2, p3;

int main()
{
	cin >> (s + 3);
	n = strlen(s + 3);
	s[0] = '.', s[1] = '/', s[2] = ',';
	p1 = 0, p2 = 1, p3 = 2;
	for (int i = 3; i <= n + 2; i++)
	{
		if (s[p2] == s[p3] and s[p3] == s[i])
			s[i] = '#';
		if (s[p1] == s[p2] and s[p3] == s[i])
			s[i] = '#';
		if (s[i] == '#')
			continue;
		p1 = p2;
		p2 = p3;
		p3 = i;
	}
	for (int i = 3; i <= n + 2; i++)
		if (s[i] != '#')
			printf("%c", s[i]);
	return 0;
}
