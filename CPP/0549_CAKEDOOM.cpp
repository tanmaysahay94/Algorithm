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

int main()
{
	LL t;
	SLL(t);
	while (t--)
	{
		LL k;
		string str;
		cin >> k >> str;
		LL len = str.length();
		if (len == 1)
		{
			if (str[0] == '?')
				str[0] = '0';
			cout << str << endl;
			continue;
		}
		int valid = 1;
		for (LL i = 0; i < len; i++)
			if (str[i] == str[(i + 1)%len] and str[i] != '?')
			{
				valid = 0;
				break;
			}
		if (!valid)
		{
			cout << "NO\n";
			continue;
		}
		if (k == 1)
		{
			cout << "NO\n";
			continue;
		}
		if (k == 2)
		{
			if (len & 1)
			{
				cout << "NO\n";
				continue;
			}
			bool possible;
			for (LL i = 0; i < 2; i++)
			{
				possible = true;
				for (LL j = 0; j < len; j++)
					if (str[j] != '?' and str[j] != '0' + (i + j)%2)
					{
						possible = false;
						break;
					}
				if (possible)
				{
					for (LL j = 0; j < len; j++)
						str[j] = '0' + (i + j)%2;
					cout << str << endl;
					break;
				}
				else
					continue;
			}
			if (!possible)
				cout << "NO\n";
			continue;
		}
		for (LL i = 0; i < len; i++)
			if (str[i] == '?')
			{
				char left = str[(i - 1 + len) % len];
				char right = str[(i + 1) % len];
				if (left != '0' and right != '0')
					str[i] = '0';
				else if (left != '1' and right != '1')
					str[i] = '1';
				else
					str[i] = '2';
			}
		cout << str << endl;
	}
	return 0;
}
