#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t;
	SLL(t);
	getchar();
	while (t--)
	{
		LL count = 0, idx = 0;
		char s[10000], c;
		scanf("%c", &c);
		while (c != '\n')
		{
			s[idx++] = c;
			scanf("%c", &c);
		}
		s[idx] = '\0';
		VLL v(26, 0);
		for (int i = 0; s[i]; i++)
		{
			if (s[i] >= 'a' and s[i] <= 'z')
				v[s[i] - 'a']++;
			else if (s[i] >= 'A' and s[i] <= 'Z')
				v[s[i] - 'A']++;
		}
		for (int i = 0; i < 26; i++)
			if (v[i])
				count++;
			else
				printf("%c", i + 'a');
		if (count == 26)
			printf("~");
		cout << endl;
	}
	return 0;
}
