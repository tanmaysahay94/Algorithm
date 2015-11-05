#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int t;
	char s[111111];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		int len = strlen(s);
		vector<pair<int, char> > v(26);
		for (int i = 0; i < 26; i++)
			v[i].first = 0, v[i].second = i + 'a';
		for (int i = 0; i < len; i++)
			v[s[i]-'a'].first++;
		sort(v.begin(), v.end(), greater<pair<int, char> >());
		bool zz = true;
		int p = 0, zzz = 0;
		for (int i = 0; i < 26; i++)
		{
			while (v[i].first--)
			{
				s[p] = v[i].second;
				p += 2;
				if (p > len - 1 and zzz == 0)
				{
					p = 1;
					zzz = 1;
				}
			}
		}
		s[len] = '\0';
		for (int i = 1; i < len and zz; i++)
			if (s[i] == s[i - 1])
				zz = false;
		if (not zz)
			printf("-1\n");
		else
			printf("%s\n", s);
	}
	return 0;
}
