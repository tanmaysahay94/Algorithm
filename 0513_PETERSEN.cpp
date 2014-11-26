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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

char ans[100010];

int check(LL startVal, string& s)
{
	LL len = s.length();
	LL cur = startVal;
	for (LL i = 0; i < len - 1; i++)
	{
		ans[i] = cur + '0';
		char next = s[i + 1];
		LL val = next - 'A';
		if (cur < 5)
		{
			if (s[i] == next)
				cur += 5;
			else if (val == (cur + 1) % 5 or val == (cur + 4) % 5)
				cur = val;
			else
				return 0;
		}
		else
		{
			LL tmp = s[i] - 'A';
			if (s[i] == next)
				cur -= 5;
			else if (val == (cur + 2) % 5 or val == (cur + 3) % 5)
				cur = val + 5;
			else
				return 0;
		}
	}
	ans[len - 1] = cur + '0';
	ans[len] = '\0';
	return 1;
}

int main()
{
	LL t;
	SLL(t);
	while (t--)
	{
		string s;
		cin >> s;
		LL startVal = s[0] - 'A';
		if (check(startVal, s))
			printf("%s\n", ans);
		else if (check(startVal + 5, s))
			printf("%s\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
