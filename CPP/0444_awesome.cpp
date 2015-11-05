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
	int i;
	char ans = '.';
	int count = 0, temp = 1;
	string s;
	cin >> s;
	for (i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			temp++;
			if (temp > count)
			{
				count = temp;
				ans = s[i];
			}
			else if (temp == count)
				if (s[i] < ans)
					ans = s[i];
		}
		else
		{
			if (temp > count)
			{
				count = temp;
				ans = s[i];
			}
			else if (temp == count)
				if (s[i] < ans)
					ans = s[i];
			temp = 1;
		}
	}
	if (temp > count)
	{
		count = temp;
		ans = s[i];
	}
	else if (temp == count)
		if (s[i] < ans)
			ans = s[i];
	cout << ans << endl << count << endl;
	return 0;
}
