#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	string s;
	bool ans = true;
	for (int i = 1; i <= 8; i++)
	{
		cin >> s;
		for (int j = 0; j < 7; j++)
		{
			if (s[j] == s[j + 1])
			{
				ans = false;
				break;
			}
		}
		if (not ans)
			break;
	}
	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
